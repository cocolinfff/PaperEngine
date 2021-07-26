# PaperEngine_V1.1build  
PaperEngine是一个基于Easyx开发的简单图像引擎项目 ~~（正如其名，稳定性像纸糊的）~~

-----

语法风格与C++基本一致，下面是几个使用教程案例  

```
#include"kernel.h"//包含项目的头文件
int main(){
    window Win(800,600);
    getchar();//防止直接退出界面，加以缓冲
    return 0;
}
```
元素类型$window$，代表新建一个长宽分别为800px,600px的界面窗口。一般在程序运行中只需要新建一个窗口。


----
```
#include"kernel.h"
void callback_button_1(){
    //触发对应事件
}
int main(){
    window Win(800,600);
    button button_1(200,200,100,100,"click me!",callback_button_1);
    getchar();
    return 0;
}
```
我们引入了新的类型$button$，构造函数中6个参数的定义分别是：按钮横坐标，按钮纵坐标，按钮宽，按钮长，文本信息，回调函数。  
**回调函数**是一个自行定义的全局函数，在鼠标触发按钮的点击事件后触发（需要注意的是，按钮一经注册就会自行监听）  
但是我们发现，运行之后并没有出现按钮。我们还需要将这个界面元素($script$)注册进已生效的界面。  

----
```
#include"kernel.h"
int sig=1;
void callback_button_1(){
    sig=0;
}
int main(){
    window Win(800,600);
    button button_1(200,200,100,100,"click me!",callback_button_1);
    Win.addScript(&button_1);//将元素注册进窗口Win
    Win.display();//展示完成的界面
    getchar();
    return 0;
}
```
这样我们就能显示已注册的按钮了，但是当我们点击按钮时并没有反应，是回调函数没有正确执行吗？  
当然不是，已生成的界面是静态的，我们还需要一个动态的主循环使得整个监听回调动起来！


---
```
#include"kernel.h"
int sig=1;
void callback_button_1(){
    sig=0;
}
int main(){
    window Win(800,600);
    button button_1(200,200,100,100,"click me!",callback_button_1);
    Win.addScript(&button_1);
    Win.display();
    while(sig){
        Win.winMain()//使整个窗口Run起来！
    }
    return 0;
}
```
在生成的窗口中，我们点击按钮后会发现整个程序停止了运行，这是因为窗口循环的条件是$sig$不为0，而我们在定义的回调函数中使得$sig$为0。则当我们点击按钮时，监听到点击事件从而触发回调函数，使得$sig$为0跳出循环。

---
以上就是该引擎的简单语法和使用教程，下面是一些函数说明。

---
```
window类：
    window::window(int,int);//分别对应新建窗口的宽和高
    void window::addScript(script*);//将一个界面元素注册进
    void deleteScript(script*);//删除一个已注册的界面元素
    int window::checkCollision(script*,script*);//检测两个元素的碰撞情况，若碰撞则返回1，否则返回0
    void window::winMain();//主循环
    void window::display();//静态展示窗口画面

button类：
    button::button(int,int,int,int,string,void (*callback)())//横坐标，纵坐标，宽，高，文本，回调函数

picture类：
    picture::picture(int,int,IMAGE*,void *(callback)())//坐标，图像文件地址，回调函数
    /***************
    *其实这里回调函数是失效的，建议直接采用[](){}的形式代替 
    *IMAGE文件需要以loadimage(IMAGE*,string);的方式从文件中加载，可参考test.cpp
    ***************/
character类：
    character::character(int,int,IMAGE*,void (*call)())//与picture基本一致，但是有回调
Move_button类：
    //这是一个典型的自建类，建议阅读
scriptPool类：
    //匿名元素池
    //文档施工中，建议自行阅读源文件
```