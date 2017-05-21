#include <iostream>
#include <stdio.h>
using namespace std;

//当传入的是整形变量的时候，在内存中另外分配了2个变量，复制了x，y的值。
//只进行了值传递，所以函数调用结束后形参被释放，不能实现实参的值交换。
void swap1(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("swap1:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
}
//虽然把变量的地址传到了函数中，但在函数内部并没有修改地址指向的内存块，而是把地址在形参上完成交换。
void swap2(int *x,int *y)
{
    int *temp;
    temp=x;
    x=y;
    y=temp;
    printf("swap2:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("swap2:*x=%d, *y=%d\n",*x,*y);
}
//使用传地址的方式，通过修改内存块来实现变量的值交换，是可以的。(swap3,swap4,swap5,swap6)
void swap3(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("swap3:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("swap3:*x=%d, *y=%d\n",*x,*y);

}
void swap4(int x[],int y[])
{
    int temp;
    temp=x[0];
    x[0]=y[0];
    y[0]=temp;
    printf("swap4:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("swap4:*x=%d, *y=%d\n",*x,*y);
}
void swap5(int x[],int y[])
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("swap5:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("swap5:*x=%d, *y=%d\n",*x,*y);
}
/*a = a ^ b ^ b;如果两个相同数异或，将会清0，因此要提前做下判断。
传统的赋值写法可适用于多种类型，其正确性也是毋庸置疑的。
而异或写法除了整型之外，不敢保证其异或操作符在与浮点或自定义类型作用时还能正确的工作。
*/
void swap6(int *x, int *y)
{
    if(*x != *y)
    {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x= *x ^ *y;
    }
    printf("swap6:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("swap6:*x=%d, *y=%d\n",*x,*y);
}
/*使用引用（&）的方式，这样是给mian函数中待交换的变量起一个别名，
并把把别名作为形参在swap4中进行处理，这其实就实现了形参和实参的地址和内容完全一样，
当然可以实现值交换，swap4的效果和swap2的一样，但这种定义方式更利于程序的调试和维护，
同时也可以减小内存开销；*/
void swap7(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("swap7:变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
}
void swap8(int **x, int **y)
{
    int *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int x,y;
    x=5;
    y=3;
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap1(x,y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//不能交换，形参传值，实际传过去是拷贝的一份，没改变主函数中x,y
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap2(&x,&y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//不能交换，函数中只是地址交换了下，地址指向的内容没有交换
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap3(&x,&y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//能交换，地址指向的内容进行了交换
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap4(&x,&y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//能交换，地址指向的内容进行交换
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap5(&x,&y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//能交换，地址指向的内容进行交换
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap6(&x,&y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//能交换，地址指向的内容进行交换
    printf("----------------------------------------------------\n");

    x=5;
    y=3;
    swap7(x,y);
    printf("main :变量地址x:%d y:%d **** 变量值x=%d, y=%d\n",&x,&y,x,y);//能交换，地址指向的内容进行交换
    printf("----------------------------------------------------\n");
    return 0;
}
