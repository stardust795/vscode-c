#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>    /* Windows 下用来切换控制台编码 */
#endif

#define MAX_TASKS 100   /* 最多存 100 条任务 */
#define MAX_TEXT  100   /* 每条任务最多 99 个字符 + 结尾的 '\0' */

/* 一条任务 */
typedef struct {
    int  id;              /* 编号，从 1 开始 */
    char text[MAX_TEXT];  /* 任务内容 */
    int  done;            /* 0 = 未完成，1 = 已完成 */
} Task;

Task tasks[MAX_TASKS];    /* 用数组存所有任务 */
int  task_count = 0;      /* 当前有几条任务 */
int  next_id    = 1;      /* 下一条任务的编号 */

/* 函数声明：先告诉编译器这些函数后面会定义 */
void print_menu(void);
void clear_input_buffer(void);
void read_line(char *buf, int size);
void add_task(void);
void list_tasks(void);

int main(void)
{
    int choice;
    int ret;

#ifdef _WIN32
    /* 让 Windows 控制台按 UTF-8 显示和读取中文，避免乱码 */
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    printf("=== 我的待办清单 ===\n");

    while (1) {                      /* 无限循环，直到用户选 0 */
        print_menu();
        printf("请输入选项: ");

        /* scanf 返回成功读到的个数；EOF 表示输入结束（例如按 Ctrl+Z） */
        ret = scanf("%d", &choice);
        if (ret == EOF) {
            printf("\n输入结束，退出。\n");
            return 0;
        }
        if (ret != 1) {
            clear_input_buffer();
            printf("输入无效，请输入数字。\n\n");
            continue;
        }
        /* scanf 只读走了数字，换行符还留在缓冲区里，要清掉 */
        clear_input_buffer();

        switch (choice) {
        case 1:
            add_task();
            break;
        case 2:
            list_tasks();
            break;
        case 0:
            printf("再见！\n");
            return 0;
        default:
            printf("没有这个选项。\n");
        }
        printf("\n");
    }
}

/* 打印菜单 */
void print_menu(void)
{
    printf("----------------------\n");
    printf("1. 添加任务\n");
    printf("2. 查看任务\n");
    printf("0. 退出\n");
    printf("----------------------\n");
}

/* 把输入缓冲区里剩下的字符（包括换行符）全部丢掉 */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* 什么都不做，只是读走 */
    }
}

/* 安全地读一行文字到 buf 里，并去掉末尾的 '\n' */
void read_line(char *buf, int size)
{
    size_t len;

    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }

    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';     /* 去掉换行符 */
    } else {
        clear_input_buffer();    /* 输入太长，丢掉多余字符 */
    }
}

/* 添加一条任务 */
void add_task(void)
{
    if (task_count >= MAX_TASKS) {
        printf("任务已满，无法继续添加。\n");
        return;
    }

    printf("请输入任务内容: ");
    read_line(tasks[task_count].text, MAX_TEXT);

    if (tasks[task_count].text[0] == '\0') {
        printf("任务内容不能为空。\n");
        return;
    }

    tasks[task_count].id   = next_id;
    tasks[task_count].done = 0;
    task_count++;
    next_id++;

    printf("已添加！\n");
}

/* 查看所有任务 */
void list_tasks(void)
{
    int i;

    if (task_count == 0) {
        printf("还没有任务。\n");
        return;
    }

    printf("---- 任务列表 ----\n");
    for (i = 0; i < task_count; i++) {
        /* done 为 1 显示 [x]，否则显示 [ ] */
        printf("%d. [%c] %s\n",
               tasks[i].id,
               tasks[i].done ? 'x' : ' ',
               tasks[i].text);
    }
}

/* ===== 接下来由你完成 =====
 * 阶段 2：
 *   选项 3：输入编号，把对应任务的 done 改成 1
 *   选项 4：输入编号，删除任务（后面的元素往前挪）
 * 阶段 3：
 *   选项 5：把所有任务写入 todo.txt
 *   选项 6：从 todo.txt 读取任务
 *
 * 先别急着写，先把阶段 1 跑起来，并试着改两处：
 *   1) 在菜单里加一行 "3. 统计" 的显示
 *   2) 让 list_tasks 在最后打印 "共 N 条，已完成 M 条"
 */
