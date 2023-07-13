#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

char userName[50] = { "cangkuguanliyuan" };
char userPwd[16] = { "123456789" };
int whethermember = 0;//会员身份标识
int iflogin = 0;
typedef struct The_members
{
    char name[15];//姓名为字符串 
    long phone; //电话号码为长整型 
    char id[11]; //账号 
    char key[20]; //密码 
}members;                                 //会员部分结构数组


typedef struct goods
{
    int id; //商品编号
    char name[20]; //商品名称
    float price; //商品单价
    int stock; //商品库存
    struct goods* next; //指向下一个节点的指针
}Goods;

typedef struct cart//该结构体为存储购物车中的信息 
{
    int id; //商品编号
    char name[20]; //商品名称
    float price; //商品单价
    int number;//购物的数量 
    struct cart* next; //指向下一个购物节点 
}Cart;


//定义全局变量
Goods* head = NULL; //定义头指针，指向链表的第一个节点

Cart* cart_head = NULL;//定义头指针，指向链表的第一个节点（购物车用）

int count = 0; //定义商品数量

//声明函数原型
void welcome(); //欢迎界面函数
void main_menu(); //主菜单函数
void shop_menu();//购物菜单函数
void input(); //录入商品信息函数
void display(); //显示商品信息函数
void statistics(); //统计商品信息函数
void save(); //保存商品信息到文件函数
void load(); //从文件读取商品信息函数
void exit_system(); //退出系统函数
void modify();//修改商品函数
int login();//管理员登陆系统 

//声明函数原型（购物车用）
void customer_buy();
void customer_cart();
void exit_system();
void checkout();
//会员系统
void vip_login();
void set3();
void registermembers();//注册账号
void MemberInput_login();//登陆账号
void memberfind();//找回密码
void cursor(int x, int y);
void progress();
//主函数
int main()
{
    load(); //调用从文件读取商品信息函数
    int choose;
    while (1) {
        welcome(); //调用欢迎界面函数
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            while (1) {
                main_menu(); //调用主菜单函数
            }
            break;
        case 2:
            while (1) {
                shop_menu(); //调用主菜单函数
            }
            break;
        }
    }
    return 0;
}

void welcome()
{
    progress();
    system("cls");

    system("color f5");
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*     欢迎使用超市管理系统      *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*   输入1进入商品管理主菜单...  *\n");
    printf("\t\t\t\t\t*   输入2进入购物主菜单...      *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\n\n\n\n");

}


int login() {
    char Name[50];
    char Password[16];
    printf("\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*        管理员登录             *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t请输入账号：");
    scanf("%s", Name);
    printf("\t\t\t\t\t请输入密码：");
    scanf("%s", Password);
    if (strcmp(Name, userName) == 0 && strcmp(Password, userPwd) == 0) {
        system("cls");
        printf("\n\n\n");
        printf("\t\t\t\t\t       登陆成功！              \n");
        iflogin = 1;
        Sleep(1000);
        system("cls");
        return 0;
    }
    else {
        printf("\t\t\t\t\t*       登陆失败！              *\n");
        int flag = 0;
        printf("\t\t\t\t\t*       请选择是否继续登录      *\n");
        printf("\t\t\t\t\t*       1：继续登录             *\n");
        printf("\t\t\t\t\t*       0：退出系统             *\n");
        scanf("%d", &flag);
        if (flag) {
            system("cls");
            return 1;
        }
        else {
            exit(0);
        }
    }


}
//主菜单函数
void main_menu()
{
    int choice; //定义用户选择变量
    system("cls"); //清屏
    system("color f5");
    if (iflogin == 0) {
        while (login());
    }
    printf("\n\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*        超市管理系统主菜单     *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    //显示不同的功能选项，如录入、显示、查询、修改、删除、排序、统计、保存、读取和退出等
    printf("\t\t\t\t\t*       1.录入商品信息          *\n");
    printf("\t\t\t\t\t*       2.显示商品信息          *\n");
    printf("\t\t\t\t\t*       3.统计商品信息          *\n");
    printf("\t\t\t\t\t*       4.修改商品信息          *\n");
    printf("\t\t\t\t\t*       0.退出系统              *\n");
    printf("\t\t\t\t\t*       ");
    scanf("%d", &choice); //输入用户选择
    switch (choice) //根据用户选择执行相应的操作
    {
    case 1: //录入商品信息
        input(); //调用录入商品信息函数
        break;
    case 2: //显示商品信息
        display(); //调用显示商品信息函数
        printf("\t\t按任意键返回主菜单...");
        getchar();
        getchar();
        break;
    case 3: //统计商品信息
        statistics(); //调用统计商品信息函数
        break;
    case 4: //删除商品信息
        modify(); //调用删除商品信息函数
        break;
    case 0: //退出系统
        exit_system(); //调用退出系统函数
        break;
    default: //无效的选择
        printf("\t\t\t*     无效的选择，请重新输入！   *\n");
        getchar();
        getchar();
        main_menu(); //重新调用主菜单函数
    }
}

//录入商品信息函数
void input()
{
    system("cls"); //清屏
    system("color f5");
    printf("\n\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*        录入商品信息界面       *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");

    printf("\t\t\t\t\t*       请输入商品编号：        *\n");
    printf("\t\t\t\t\t        ");
    int reid;
    int temp = 1;
    scanf("%d", &reid); //输入商品编号
    Goods* pid;
    pid = head;
    while (pid != NULL) //遍历链表，打印每个节点的数据域
    {
        if (pid->id == reid) {
            temp = 0;
            break;
        }
        pid = pid->next; //将p指向下一个节点
    }

    if (temp == 1) {//验证重复id

        Goods* p, * q; //定义两个指针变量
        p = (Goods*)malloc(sizeof(Goods)); //动态分配内存空间
        if (p == NULL) //判断内存是否分配成功
        {
            printf("\t\t\t\t\t*       内存分配失败！         *\n");
            exit(1); //退出程序
        }
        p->id = reid;
        printf("\t\t\t\t\t*       请输入商品名字：        *\n");
        printf("\t\t\t\t\t        ");
        scanf("%s", p->name); //输入商品名称
        printf("\t\t\t\t\t*       请输入商品单价：        *\n");
        printf("\t\t\t\t\t        ");
        scanf("%f", &p->price); //输入商品单价
        printf("\t\t\t\t\t*       请输入商品库存：        *\n");
        printf("\t\t\t\t\t        ");
        scanf("%d", &p->stock); //输入商品库存
        p->next = NULL; //初始化指针域为NULL
        if (head == NULL) //判断链表是否为空
        {
            head = p; //将p赋值给头指针
        }
        else //链表不为空
        {
            q = head; //将头指针赋值给q
            while (q->next != NULL) //遍历链表，找到最后一个节点
            {
                q = q->next;
            }
            q->next = p; //将p插入到最后一个节点的后面
        }
        count++; //商品数量加1
        system("cls");
        save();
        printf("\t\t\t\t\t*                               *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     商品信息录入成功！        *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     请选择是否继续录入        *\n");
        printf("\t\t\t\t\t*     1:继续录入	 	*\n");
        printf("\t\t\t\t\t*     2:返回管理系统主菜单	*\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
    }
    else {
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     商品信息录入重复！        *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     请选择是否继续录入        *\n");
        printf("\t\t\t\t\t*     1:继续录入	 	*\n");
        printf("\t\t\t\t\t*     2:返回管理系统主菜单	*\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
    }
}

//显示商品信息函数
void display()
{
    system("cls"); //清屏
    system("color f5");
    printf("\n\n\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    printf("\t*                                显示商品信息界面                                       *\n");
    printf("\t*                                                                                       *\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    Goods* p; //定义一个指针变量
    p = head; //将头指针赋值给p
    if (p == NULL) //判断链表是否为空
    {
        printf("\t*       暂无商品信息！                                                                  *\n");
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t按任意键返回主菜单...");
        getchar();
        getchar();
        return; //返回主函数
    }
    else //链表不为空
    {
        printf("\t*商品编号\t商品名称\t商品单价\t商品库存\t                        *\n");
        while (p != NULL) //遍历链表，打印每个节点的数据域
        {
            printf("\t*%d\t\t%8s\t%.2f\t\t%d\t\t\t", p->id, p->name, p->price, p->stock);
            printf("                *\n");
            p = p->next; //将p指向下一个节点
        }
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");

    }
}


//统计商品信息函数
void statistics()
{
    system("color f5");
    system("cls"); //清屏
    printf("\n\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*        统计商品信息界面       *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    Goods* p; //定义一个指针变量
    p = head; //将头指针赋值给p
    if (p == NULL) //判断链表是否为空
    {
        printf("\t\t\t\t\t*       暂无商品信息！         *\n");
        printf("\t\t\t\t\t*                               *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t按任意键返回主菜单...");
        getchar();
        getchar();
        return; //返回主函数
    }
    else //链表不为空
    {
        int num = 0; //定义商品总数变量
        float value = 0.0; //定义商品总价值变量
        float average = 0.0; //定义商品平均单价变量
        while (p != NULL) //遍历链表，累加各项数据
        {
            num++; //商品总数加1
            value += p->price * p->stock; //商品总价值等于单价乘以库存的和
            average += p->price; //商品平均单价等于各个商品单价的和
            p = p->next; //将p指向下一个节点
        }
        average /= num; //商品平均单价等于各个商品单价的和除以商品总数
        printf("\t\t\t\t\t       商品总数：%d             \n", num); //打印商品总数
        printf("\t\t\t\t\t       商品总价值：%.2f         \n", value); //打印商品总价值，保留两位小数
        printf("\t\t\t\t\t       商品平均单价：%.2f       \n", average); //打印商品平均单价，保留两位小数
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t按任意键返回管理系统主菜单...");
        getchar();
        getchar();
    }
}

//保存商品信息到文件函数
void save()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*     保存商品信息界面          *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    Goods* p; //定义一个指针变量
    p = head; //将头指针赋值给p
    if (p == NULL) //判断链表是否为空
    {
        printf("\t\t\t\t\t*       暂无商品信息！         *\n");
        printf("\t\t\t\t\t*                               *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t按任意键返回主菜单...");
        getchar();
        getchar();
        return; //返回主函数
    }
    else //链表不为空
    {
        FILE* fp; //定义一个文件指针变量
        fp = fopen("goods.txt", "w"); //以写入模式打开一个名为goods.txt的文本文件，如果不存在则创建
        if (fp == NULL) //判断文件是否打开成功
        {
            printf("\t\t\t*       文件打开失败！         *\n");
            exit(1); //退出程序
        }
        while (p != NULL) //遍历链表，将每个节点的数据域写入到文件中，每个数据之间用空格隔开，每个节点用换行符结束
        {
            fprintf(fp, "%d %s %.2f %d\n", p->id, p->name, p->price, p->stock);
            p = p->next; //将p指向下一个节点
        }
        fclose(fp); //关闭文件
        printf("\t\t\t\t\t*                               *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     商品信息保存成功！        *\n");
        printf("\t\t\t\t\t*********************************\n");
    }
}

//从文件读取商品信息函数
void load()
{
    FILE* fp; //定义一个文件指针变量
    fp = fopen("goods.txt", "r"); //以只读模式打开一个名为goods.txt的文本文件
    if (fp == NULL) //判断文件是否打开成功
    {
        printf("\t\t\t\t\t*       文件打开失败！         *\n");
        return; //返回主函数
    }
    Goods* p, * q; //定义两个指针变量
    p = (Goods*)malloc(sizeof(Goods)); //动态分配内存空间
    if (p == NULL) //判断内存是否分配成功
    {
        printf("\t\t\t\t\t*       内存分配失败！         *\n");
        exit(1); //退出程序
    }
    while (fscanf(fp, "%d %s %f %d", &p->id, p->name, &p->price, &p->stock) != EOF) //从文件中读取每个节点的数据域，直到文件结束
    {
        p->next = NULL; //初始化指针域为NULL
        if (head == NULL) //判断链表是否为空
        {
            head = p; //将p赋值给头指针
        }
        else //链表不为空
        {
            q = head; //将头指针赋值给q
            while (q->next != NULL) //遍历链表，找到最后一个节点
            {
                q = q->next;
            }
            q->next = p; //将p插入到最后一个节点的后面
        }
        count++; //商品数量加1
        p = (Goods*)malloc(sizeof(Goods)); //为下一个节点分配内存空间
        if (p == NULL) //判断内存是否分配成功
        {
            printf("\t\t\t\t\t*       内存分配失败！         *\n");
            exit(1); //退出程序
        }
    }
    fclose(fp); //关闭文件
}


//退出系统函数
void exit_system()
{
    save();
    system("cls"); //清屏
    printf("\n\n\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*        退出系统界面           *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t\t*                               *\n");
    Goods* p, * q; //定义两个指针变量
    p = head; //将头指针赋值给p
    while (p != NULL) //遍历链表，释放每个节点的内存空间
    {
        q = p->next; //将q指向p的下一个节点
        free(p); //释放p所指向的内存空间
        p = q; //将p指向q
    }
    head = NULL; //将头指针置为NULL
    count = 0; //将商品数量置为0
    printf("\t\t\t\t\t*       感谢您使用本系统！      *\n");
    printf("\t\t\t\t\t*                               *\n");
    printf("\t\t\t\t\t*********************************\n");
    printf("\t\t\t\t按任意键退出...");
    getchar();
    exit(0);

}


// 修改商品函数
void modify() {
    int id; // 定义要修改的商品编号变量
    Goods* p; // 定义一个商品指针
    display();
    printf("请输入要修改的商品的编号：\n");
    scanf("%d", &id); // 获取用户输入的商品编号
    p = head; // 从头指针开始遍历商品链表
    while (p != NULL) { // 如果链表不为空
        if (p->id == id) { // 如果找到了相同编号的商品，提示原来的信息并获取新的信息
            printf("原来的商品信息如下：\n");
            printf("编号：%d\n", p->id);
            printf("名称：%s\n", p->name);
            printf("价格：%lf\n", p->price);
            printf("数量：%d\n", p->stock);
            printf("请输入新的商品名称编号：\n");
            scanf("%d", &p->id); // 获取用户输入的新商品名称
            printf("请输入新的商品名称：\n");
            scanf("%s", p->name); // 获取用户输入的新商品名称
            printf("请输入新的商品价格：\n");
            scanf("%f", &p->price); // 获取用户输入的新商品价格
            printf("请输入新的商品数量：\n");
            scanf("%d", &p->stock); // 获取用户输入的新商品数量
            printf("修改商品成功！\n"); // 提示成功信息
            save();//输入后马上保存
            return;
        }
        p = p->next; // 指向下一个商品节点
    }
    printf("没有找到该编号的商品，无法修改！\n"); // 如果没有找到相同编号的商品，提示错误信息并返回
}





void shop_menu() {
    int choice; //定义用户选择变量
    system("cls"); //清屏
    printf("\n\n\n");
    printf("\t\t\t\t\t\t   WELCOMOE!\n");
    printf("\t    /\\__/\\          \t\t*********************************\t\t    /\\__/\\          \n");
    printf("\t   /`    '\\         \t\t*                               *\t\t   /`    '\\         \n");
    printf("\t === 0  0 ===       \t\t*        购物系统主菜单         *\t\t === 0  0 ===       \n");
    printf("\t   \\  --  /         \t\t*                               *\t\t   \\  --  /         \n");
    printf("\t  /        \\        \t\t*                               *\t\t  /        \\        \n");
    printf("\t /          \\       \t\t*                               *\t\t /          \\       \n");
    printf("\t|            |      \t\t*                               *\t\t|            |      \n");
    printf("\t \\  ||  ||  /       \t\t*                               *\t\t \\  ||  ||  /       \n");
    printf("\t  \\_oo__oo_/#######o\t\t*********************************\t\t  \\_oo__oo_/#######o\n");
    printf("\t\t\t\t\t*                               *\n");
    //显示不同的功能选项
    printf("\t\t\t\t\t*        1.购买商品             *\n");
    printf("\t\t\t\t\t*        2.打开购物车           *\n");
    if (!whethermember) {
        printf("\t\t\t\t\t*        3.会员登陆             *\n");
    }
    printf("\t\t\t\t\t*        0.退出系统             *\n");
    printf("\t\t\t\t\t        ");
    printf("\n\t\t\t\t\t 请选择：");
    scanf("%d", &choice); //输入用户选择
    system("cls");
    switch (choice) //根据用户选择执行相应的操作
    {
    case 1: //购买商品
        customer_buy(); //调用购买商品函数
        break;
    case 2: //打开购物车
        customer_cart(); //调用统计商品信息函数
        break;
    case 3: //会员登陆
        vip_login(); //调用会员登陆
        break;
    case 0: //退出系统
        exit_system(); //调用退出系统函数
        break;
    default: //无效的选择
        printf("\t\t\t*     无效的选择，请重新输入！   *\n");
        getchar();
        getchar();
        shop_menu(); //重新调用主菜单函数
    }
}

//购买商品函数
void customer_buy()
{
    display();
    printf("\n\n\n");
    printf("\t*********************************\n");
    printf("\t*                               *\n");
    printf("\t*          购买商品界面         *\n");
    printf("\t*                               *\n");
    printf("\t*********************************\n");
    printf("\t*                               *\n");
    Cart* p1, * q1; //定义两个指针变量
    p1 = (Cart*)malloc(sizeof(Cart)); //动态分配内存空间
    if (p1 == NULL) //判断内存是否分配成功
    {
        printf("\t\t\t\t\t*       内存分配失败！         *\n");
        exit(1); //退出程序
    }
    int id; // 定义要购买的商品编号变量
    int buy_number;
    Goods* p; // 定义一个商品指针
    printf("\t*请输入要购买的商品的编号：");
    scanf("%d", &id); // 获取用户输入的商品编号
    p = head; // 从头指针开始遍历商品链表
    while (p != NULL) { // 如果链表不为空
        if (p->id == id) { // 如果找到了相同编号的商品，提示原来的信息并获取新的信息
            printf("\t*商品信息如下：\n");
            printf("\t*编号：%d\n", p->id);
            printf("\t*名称：%s\n", p->name);
            printf("\t*价格：%lf\n", p->price);

            printf("\t*输入购买数量:");
            scanf("%d", &buy_number);
            if (buy_number <= p->stock) {
                p1->id = p->id;
                strcpy(p1->name, p->name);
                p1->price = p->price;

                p->stock -= buy_number;
                p1->number = buy_number;

                p1->next = NULL; //初始化指针域为NULL
                if (cart_head == NULL) //判断链表是否为空
                {
                    cart_head = p1; //将p赋值给头指针

                    system("cls");
                    printf("\n\n");
                    printf("\t\t\t\t\t*********************************\n");
                    printf("\t\t\t\t\t*       加入购物车成功！        *\n");
                    printf("\t\t\t\t\t*********************************\n");
                    Sleep(1000);
                    return;
                }
                else //链表不为空
                {
                    q1 = cart_head; //将头指针赋值给q
                    while (q1->next != NULL) //遍历链表，找到最后一个节点
                    {
                        q1 = q1->next;
                    }
                    q1->next = p1; //将p插入到最后一个节点的后面

                    system("cls");
                    printf("\t\t\t\t\t*********************************\n");
                    printf("\t\t\t\t\t*       加入购物车成功！        *\n");
                    printf("\t\t\t\t\t*********************************\n");
                    printf("\t\t\t\t按任意键返回购物系统主菜单...");
                    getchar();
                    getchar();
                    return;
                }
            }
            else {
                printf("库存不足!按任意键继续");
                getchar();
                getchar();
                return;
            }
        }
        p = p->next; // 指向下一个商品节点
    }
    printf("没有找到该编号的商品，无法购买！\n"); // 
    printf("请按任意键返回\n");
    getchar();
    getchar();

}

void checkout() {
    save();
}


void customer_cart() {
    double sum = 0;
    system("cls"); //清屏
    printf("\n\n\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    printf("\t*                                显示商品信息界面                                       *\n");
    printf("\t*                                                                                       *\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    Cart* p1; //定义一个指针变量
    p1 = cart_head; //将头指针赋值给p
    if (p1 == NULL) //判断链表是否为空
    {
        printf("\t*       暂无商品信息！                                                                  *\n");
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t按任意键返回购物系统主菜单...");
        getchar();
        getchar();
        return; //返回主函数
    }
    else //链表不为空
    {
        printf("\t*商品编号\t商品名称\t商品单价\t购买数量\t                        *\n");
        while (p1 != NULL) //遍历链表，打印每个节点的数据域
        {
            printf("\t*%d\t\t%8s\t%.2f\t\t%d\t\t", p1->id, p1->name, p1->price, p1->number);
            if (strlen(p1->name) < 8) //根据商品名称的长度，调整输出格式
            {
                printf("\t");
            }
            printf("                *\n");
            sum += p1->price * p1->number;
            p1 = p1->next; //将p指向下一个节点
        }


        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t总价格:%.2f\n", sum);
        printf("\t\t输入1结账，输入0返回购物系统主菜单...\n");
        if (whethermember) {
            printf("\t\t会员打折后总价格:%.2f\n", sum * 0.95);
        }
        else {
            printf("\t\t您未登陆会员,如需登录，请按0返回登录\n");
        }
        int choose;
        scanf("%d", &choose);
        if (choose == 1) {
            printf("\t\t结账成功!");
            save();
            exit(0);
        }
    }
}

//会员系统 
void vip_login() {
    set3();
}

void set3()
{

    int choose;         //用户输入的选择 
    int ture = 1;       //循环判断真假 


    while (ture != 0)
    {
        system("color f5");
        printf("\n\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*         会员登录系统          *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*         1.注册会员            *\n");
        printf("\t\t\t\t\t*         2.登录会员            *\n");
        printf("\t\t\t\t\t*         3.忘记密码            *\n");
        printf("\t\t\t\t\t*         0.返回                *\n");
        printf("\t\t\t\t\t*         请选择：");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            getchar();
            system("cls");
            registermembers();    //注册账户
            break;

        case 2:
            system("cls");
            MemberInput_login();  //登录账户
            getchar();
            ture = 0;
            break;

        case 3:
            getchar();
            memberfind();       //找回密码 
            break;
        case 0:
            ture = 0;
            break;
        default:
            getchar();
            rewind(stdin);      //清除键盘缓存 
            printf("输入错误，请重新输入！\n");
            system("pause");
            system("cls");
            break;
        }

    }

}

void Membership_File()
{
    FILE* fp;
    fp = fopen("members.txt", "a");
    if ((fp = fopen("members.txt", "rb")) == NULL)               /*判断文件是否存在*/
    {
        if ((fp = fopen("members.txt", "wb+")) == NULL)          /*读写二进制*/
        {
            printf("无法建立文件！\n");
            exit(0);

        }
    }
}

/*-------
 注册账号
---------*/

void registermembers()
{
    //按结构体的大小，一次写入或者读入1个结构体大小

    members a, b; //结构体 The_members 重命名定义
    FILE* fp;  //定义头文件 fp 


    char temp[20];//存放密码，二次确认 
    int count = 0;
    int flag = 1;
    char signchoice;
    system("cls");//清屏 
    Sleep(800);
    system("color f5");
    printf("                        --------------------------\n");
    printf("                          欢迎来到会员注册界面！  \n");
    printf("                        --------------------------\n");
    fflush(stdin); //清空输入缓存的函数，在输入字符之前调用它可以清除之前未读取的字符。
    Sleep(500);   //Sleep是指输出的间隔 
    fp = fopen("members.txt", "a");
    fp = fopen("members.txt", "r");
    fread(&b, sizeof(struct The_members), 1, fp); //读出数据存放的地址 b  
    printf("\t请输入姓名：");
    scanf("%s", &a.name);
    printf("\t请输入电话号码：");
    scanf("%ld", &a.phone);
    printf("\t请输入账号：");
    scanf("%s", &a.id);
    while (flag)
    {
        if (strcmp(a.id, b.id)) /*如果两串不相等*/
        {
            if (!feof(fp))    /*如果未到文件尾*/
            {
                fread(&b, sizeof(struct The_members), 1, fp);
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("\t此用户名已存在！请重新选择！");
            getchar();
            rewind(stdin);
            Sleep(800);
            system("cls");
            return;
        }
    }
    printf("\t请输入密码：");
    scanf(" %s", &a.key);
    printf("\t请确认密码：");
    scanf(" %s", &temp);
    do {
        if (!strcmp(a.key, temp))
        {
            fp = fopen("members.txt", "a");//追加一个账号 
            fwrite(&a, sizeof(struct The_members), 1, fp);/* a 待写入文件的指针 （地址）*/
            printf("会员注册成功，已成功绑定手机，请返回登录界面进行登录。。。\n");
            system("cls");
            FILE* ph;
            ph = fopen("phone.txt", "w");
            ph = fopen("phone.txt", "a");
            fprintf(ph, "【钱多多超市】您已成功开通钱多多超市会员服务，自动开启推荐服务，我们将持续为您推送优惠商品，退订回T\n");
            fclose(ph);
            Sleep(500);
            fclose(fp);
            return;
        }
        else
        {
            printf("两次密码不匹配！请重新输入！\n");
            getchar();
            scanf("%s", &a.key);
            printf("请确认密码\n");
            scanf("%s", &temp);
        }
    } while (1);

}


void  MemberInput_login()
{
    members a, b;  //定义结构体The_members别名

    FILE* fp;   //文件 
    int i = 0;

    system("cls");

    system("color f5");

    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t欢迎来到会员登录界面！\n");

    Sleep(1500);
    system("cls");//清屏 
    Sleep(800);

    fp = fopen("members.txt", "r");

    fread(&b, sizeof(struct The_members), 1, fp); //读入一个结构体字符块 写入b

    printf("\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入用户名：                             │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //如果有此用户名
        {
            break;
        }

        else
        {
            if (fp == NULL)
            {
                printf("还未拥有会员注册信息，请注册\n");
                system("pause");
                system("cls");
                set3();
            }


            if (!feof(fp))  //如果文件没有读完                            

            {
                fread(&b, sizeof(struct The_members), 1, fp);
                /*读出数据 b 存放的地址位置，内存大小，每次读取一个数据块 1 ，以读的方式打开文件*/
            }

            else
            {
                printf("此会员名不存在，请重新选择！\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }

    printf("\n\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入密码：                               │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 8);

    while ((a.key[i] = getch()) != 13)//getch()返回值是一个键值，回车的键值是13
    {                                   //将输入的密码存储在数组中在屏幕上输出‘* ’代替数字 
        i++;
        printf("*");//隐藏密码
    }
    a.key[i] = '\0';//把最后的回车变成结束符（数组） 
    printf("\n");

    do {

        if (strcmp(a.key, b.key) == 0)            /*如果密码匹配*/

        {
            fclose(fp);

            Sleep(500);
            printf("\n\n\t\t\t\t\t\tVIP登录进行中");

            Sleep(500);
            printf(".");
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(1000);
            fflush(stdin);

            printf("\n\n\t\t\t\t\t\t登 录 成 功，即 刻 享 受 会 员 权 益 !");
            FILE* ph;
            ph = fopen("phone.txt", "a");
            fprintf(ph, "\n【钱多多超市】您好，尊敬的会员%s，您已成功登录，衷心祝愿您有一个良好的购物体验。若非本人操作请及时联系客服处理\n", a.id);

            fprintf(ph, "\n【钱多多超市】坤哥哥玩偶，11.99元/件起;香蕉君手办,29.99/件起；500g鸭脖，18.99/袋起。晚8点线上开售。速戳https://m.tb.cn/h.5bystcP?tk=r2w5dtmg68M.退订回T");
            fclose(ph);
            Sleep(1000);
            system("cls");
            printf("您 好，尊 敬 的 会 员%s\n", a.id);
            whethermember = 1;
            return;
        }
        else
        {

            printf("密码错误！");
            printf("\n\n\n");
            printf("\t\t\t\t   │============================================│\n");
            printf("\t\t\t\t   │ 请输入密码：                         │\n");
            printf("\t\t\t\t   │============================================│\n");

            cursor(50, 13);
            scanf("%s", &a.key);

        }


    } while (strcmp(a.key, b.key) == 0);

}






/*---------
 找回密码
----------*/

void memberfind()  //按结构体的大小，一次写入或者读入1个结构体大小
{
    members a, b;//结构体 The_users 重命名定义
    FILE* fp;

    char temp[20];
    //int count = 0;

    printf("欢 迎 来 到 找 回 密 码 界 面 ，密 码 找 回 需 要 对 您 进 行 身 份 验 证\n");
    Sleep(1000);

    fp = fopen("members.txt", "r");

    fread(&b, sizeof(struct The_members), 1, fp); //读入一个结构体字符块 写入b

    system("cls");
    system("color f5");

    printf("\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入账号：                         │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //如果有此用户名
        {
            break;
        }

        else
        {
            if (!feof(fp))  //如果文件没有读完                            

            {
                fread(&b, sizeof(struct The_members), 1, fp);
                //从文件中拷贝一个大小为struct The_members的数据 
            }

            else
            {
                printf("此 用 户 名 不 存 在 ，请 重 新 选 择 ！\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }


    printf("\n\n");
    printf("请 输 入 姓 名：\n");
    scanf("%s", &a.name);

    do
    {
        if (strcmp(a.name, b.name))
        {
            printf("姓 名 输 入 错 误 ！请 重 新 输 入 ！\n");
            getchar();
            scanf("%s", &a.name);
        }
    } while (strcmp(a.name, b.name));

    printf("请 输 入 电 话 号 码 ：\n");
    scanf("%ld", &a.phone);

    do {
        if (a.phone != b.phone)
        {
            printf("电 话 号 码 输 入 错 误 ！请 重 新 输 入 ！\n");
            getchar();
            scanf("%ld", &a.phone);
        }
    } while (a.phone != b.phone);


    long checknumber;
    srand(time(0));
    char g[5], w[5];
    char first, second, third, forth;
    int i, j, k;
    for (i = 0; i < 4; i++)
    {
        first = rand() % 10 + 48;
        second = rand() % 26 + 65;
        third = rand() % 26 + 97;
        forth = rand() % 100 + 1;
        if (forth < 33) g[i] = first;
        else
            if (forth >= 33 && forth < 63) g[i] = second;
            else g[i] = third;

    }
    FILE* ph;
    ph = fopen("phone.txt", "a");//追加一个账号         
    fprintf(ph, "\n【钱多多超市】您好，尊敬的用户%s，本次身份验证的验证码为：%s。若非本人操作请及时联系客服处理\n", a.id, g);
    fclose(ph);
    printf("验 证 码 已 经 发 送 至 您 的 手 机\n");
    printf("请 输 入 验 证 码 ：\n");
    scanf("%s", w);
    while (strcmp(g, w))
    {
        printf("验 证 码 错 误，请 重 新 输 入 \n:");
        scanf("%s", w);
    }
    printf("验证成功！");
    printf("您 的 密 码 为 ：%s, 请 记 住 它 哟 ~\n", b.key);



    Sleep(3000);
    system("pause");
    system("cls");
}





void cursor(int x, int y)
{
    COORD pos;          //COORD是Windows API中定义的一种结构 
    HANDLE h;           //HANDLE:句柄
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //获得当前输出窗口的句柄
    SetConsoleCursorPosition(h, pos);

}

/*-------
 进度条
-------*/

void progress()
{
    int i;
    int j;

    system("cls");

    printf("\n\n\n\n\n\t\t\t\t    \033[0;33;40m     正 在 进 入 系 统，请 稍 后 . . .   \033[0m");

    const char* LastStr = "[--------------------------------------------------] 100%";
    // 进度条标志，可以改用"*"或其它符号
    const char ProgressIcon = '*';
    // 进度每加5，进度条就会加一格，注意Step值要和LastStr中的"-"数量相匹配，两者相乘等于100
    const int Step = 2;
    // 总共需要多少进度标志，即LastStr中"-"的数量
    const int IconMaxNum = 50;

    printf("\n\n    \t\t\t\t");
    for (i = 0; i <= 100; ++i)
    {
        // -------------- 打印进度条 --------------
        printf("<");
        int currentIndex = i / Step;
        for (j = 0; j < IconMaxNum; ++j)
        {
            if (j < currentIndex)
            {
                printf("\033[0;33;1m%c", ProgressIcon); // 打印进度条标志
            }
            else
            {
                printf(" "); // 未达进度则打印空格
            }
        }
        printf("> ");
        // -------- 打印数字进度 ----------
        printf("\033[0;35;0m%3d%%", i);
        fflush(stdout);
        // 每隔100ms打印一次，这里同时每隔100ms会让进度加1
        Sleep(10);
        for (j = 0; j < strlen(LastStr); ++j)  //strlen 字符串处理函数
        {
            printf("\b");               // 回删字符，让数字和进度条原地变化
        }
        fflush(stdout); //清空输出缓存区
    }

    printf("\n\n");
    return;

}