# 解一元N次方程

1. 此程序用**二分法**、**牛顿迭代法**和**弦截法**解一元N次方程；
2. 第一次使用将自动创建**solving-equations.txt**；
3. 计算内容写在**solving-equations.txt**中；
4. 各数字之间加上空格，输入到文件时按以下格式：

```ansi
f(x) = -x² -2.2x +3

-1 2 -2.2 1 3 0
```

## 如何下载？

前往 [GitHub Release](https://github.com/BlazeSnow/solving-equations/releases/latest) 下载对应系统的可执行文件。

文件命名格式为 `solving-equations-<版本>-<系统>-<架构>`，各平台对应关系如下：

| 文件名后缀           | 适用平台               |
| -------------------- | ---------------------- |
| `-windows-x64.exe`   | Windows x64            |
| `-windows-arm64.exe` | Windows ARM64          |
| `-linux-x64`         | Linux x64              |
| `-linux-arm64`       | Linux ARM64            |
| `-macos-x64`         | macOS（Intel）         |
| `-macos-arm64`       | macOS（Apple Silicon） |

## Linux / macOS 额外处理

```sh
sudo chmod +x <可执行文件>
```

## 更新日志

见 [CHANGELOG.md](./CHANGELOG.md)

## 许可证

[MIT](./LICENSE)
