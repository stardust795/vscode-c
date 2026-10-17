# 命令行待办清单（学习项目）

一个只用 C 标准库的小项目，用来练习：
结构体、数组、字符串、输入缓冲、文件读写、多文件拆分、Git、调试。

## 路线图

- [x] 阶段 1：菜单 + 内存中的添加/查看（main.c）
- [ ] 阶段 2：标记完成、删除任务
- [ ] 阶段 3：保存到文件、启动时读取
- [ ] 阶段 4：拆成 main.c / todo.c / todo.h
- [ ] 阶段 5：加单元测试、用 Git 管理版本

## 编译运行（在 todo 目录下）

```powershell
gcc -g -Wall main.c -o todo.exe
.\todo.exe
```

## VS Code 里调试

1. 打开 `main.c`
2. 在行号左侧点一下，打红点（断点）
3. 按 `F5`，选择 `C++ (GDB/LLDB)` -> `gcc.exe 生成和调试活动文件`

## 常用命令

```powershell
gcc -g -Wall main.c -o todo.exe   # 编译，-Wall 打开所有警告
.\todo.exe                        # 运行
git status                        # 查看改了哪些文件
git add .                         # 暂存
git commit -m "说明"              # 提交
```
