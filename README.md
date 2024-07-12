# 写在最前

1. 此程序用**二分法**、**牛顿迭代法**和**弦截法**解一元N次方程；
2. 第一次使用将自动创建**BlazeSnow 解方程.txt**；
3. 计算内容写在**BlazeSnow 解方程.txt**中；
4. 各数字之间加上空格
   > **f(x) = -x² -2.2x +3**

   输入到文件时按以下格式：
   ```
   -1 2 -2.2 1 3 0
   ```

# 更新日志

- **2024年7月12日20点10分**
	- 重置代码为拆分前状态，准备重新拆分
- **2024年7月11日16点07分**
	- 拆分```main.cpp```为多个```cpp```和```h```文件，为后续新功能加入建设基础
- **2024年5月17日13点22分**
	- 使用```vector<结构体>```重写程序
- **2024年4月17日12点53分**
	- 将仓库从```Gitee```转移到```GitHub```
- **2024年4月10日20点29分**
	- 嵌套过于复杂，因此删除三角函数支持
- **2024年4月4日07点58分**
	- 更新支持了三角函数
- **2024年4月3日22点35分**
	- 将计算```f(x)```的函数移入总```class```
- **2024年4月3日18点14分**
	- 添加了弦截法
- **2024年4月3日17点56分**
	- 添加了读取文件成功后的方程显示
- **2024年3月30日14点51分**
	- 修复了次数统计```times```少1次的问题
- **2024年3月30日14点35分**
	- 优化次数统计代码
	- 优化文字描述
	- 整合输出```putOutAnswer```到总```class```
	- 整合次数统计```timeLimit```到总```class```
	- 优化代码注释
- **2024年3月28日22点01分**
	- 用```class```将二分法和牛顿迭代法整合在一起
- **2024年3月9日12点59分**
	- 优化了代码行数，删除了主程序中的```temp```数值；
	- 优化了注释内容
- **2024年3月9日12点29分**
	- 用二分法解方程的程序修改，写成了牛顿迭代法解方程程序
- **2024年3月9日11点57分**
	- 优化了文字描述
- **2024年3月9日11点03分**
	- 优化了注释内容；
	- 优化了a和b的结果一正一负的检查，从**相乘<=0**，改为：**检查a正b负或a负b正**；
	- 由**第2点**解决了函数在区间内导数为负数时无法得出计算结果的问题
- **2024年3月9日10点31分**
	- 优化数组为全局数组，减少代码数量；
	- 增加了数组溢出检查；
	- 修改```double```为```long double```，支持15位小数；
	- 增加了迭代次数```times```统计；
	- 增加了开始时检查是否创建文件输入问题；
	- 优化了文字描述
- **2024年3月9日10点05分**
	- 此程序用于解一元N次方程
