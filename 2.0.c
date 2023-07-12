#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char userName[50] = { "cangkuguanliyuan" };
char userPwd[16] = { "123456789" };

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
    system("cls");
    printf("\t\t   _______   _______   _______ \n");
    printf("\t\t  / _____ \\ / _____ \\ / _____ \\\n");
    printf("\t\t / /     \\ V /     \\ V /     \\\n");
    printf("\t\t| |      | | |     | | |     | |\n");
    printf("\t\t|_|      |_| |     |_| |     |_|\n");
    printf("\t\t \\ \\_____/ |\\_____/ |\\_____/ /\n");
    printf("\t\t  \\_______/  \\_______/ \\_______/\n");

    printf("\n\n");
    printf("\t\t*********************************\n");
    printf("\t\t*                               *\n");
    printf("\t\t*     欢迎使用超市管理系统      *\n");
    printf("\t\t*                               *\n");
    printf("\t\t*   输入1进入商品管理主菜单...  *\n");
    printf("\t\t*   输入2进入购物主菜单...      *\n");
    printf("\t\t*                               *\n");
    printf("\t\t*********************************\n");
    printf("\n\n\n\n");

}


int login() {
    char Name[50];
    char Password[16];
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*       管理员登录              *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t请输入账号：");
    scanf("%s", Name);
    printf("\t\t\t请输入密码：");
    scanf("%s", Password);
    if (strcmp(Name, userName) == 0 && strcmp(Password, userPwd) == 0) {
        system("cls");
        printf("\n\n");
        printf("\t\t\t       登陆成功！              \n");
        sleep(1);
        system("cls");
        return 0;
    }
    else {
        printf("\t\t\t*       登陆失败！              *\n");
        int flag = 0;
        printf("\t\t\t*       请选择是否继续登录      *\n");
        printf("\t\t\t*       1：继续登录             *\n");
        printf("\t\t\t*       0：退出系统             *\n");
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
    while (login());
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        超市管理系统主菜单     *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    //显示不同的功能选项，如录入、显示、查询、修改、删除、排序、统计、保存、读取和退出等
    printf("\t\t\t*       1.录入商品信息          *\n");
    printf("\t\t\t*       2.显示商品信息          *\n");
    printf("\t\t\t*       3.统计商品信息          *\n");
    printf("\t\t\t*       4.修改商品信息          *\n");
    printf("\t\t\t*       0.退出系统              *\n");
    printf("\t\t\t*       ");
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
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        录入商品信息界面       *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");

    printf("\t\t\t*       请输入商品编号：        *\n");
    printf("\t\t\t        ");
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
            printf("\t\t\t*       内存分配失败！         *\n");
            exit(1); //退出程序
        }
        p->id = reid;
        printf("\t\t\t*       请输入商品名字：        *\n");
        printf("\t\t\t        ");
        scanf("%s", p->name); //输入商品名称
        printf("\t\t\t*       请输入商品单价：        *\n");
        printf("\t\t\t        ");
        scanf("%f", &p->price); //输入商品单价
        printf("\t\t\t*       请输入商品库存：        *\n");
        printf("\t\t\t        ");
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
        save();
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     商品信息录入成功！        *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     请选择是否继续录入        *\n");
        printf("\t\t\t*     1:继续录入	 	*\n");
        printf("\t\t\t*     2:返回管理系统主菜单	*\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
    }
    else {
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     商品信息录入重复！        *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     请选择是否继续录入        *\n");
        printf("\t\t\t*     1:继续录入	 	*\n");
        printf("\t\t\t*     2:返回管理系统主菜单	*\n");
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
    system("cls"); //清屏
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        统计商品信息界面       *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    Goods* p; //定义一个指针变量
    p = head; //将头指针赋值给p
    if (p == NULL) //判断链表是否为空
    {
        printf("\t\t\t*       暂无商品信息！         *\n");
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t按任意键返回主菜单...");
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
        printf("\t\t\t       商品总数：%d             \n", num); //打印商品总数
        printf("\t\t\t       商品总价值：%.2f         \n", value); //打印商品总价值，保留两位小数
        printf("\t\t\t       商品平均单价：%.2f       \n", average); //打印商品平均单价，保留两位小数
        printf("\t\t\t*********************************\n");
        printf("\t\t按任意键返回管理系统主菜单...");
        getchar();
        getchar();
    }
}

//保存商品信息到文件函数
void save()
{
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*     保存商品信息界面          *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    Goods* p; //定义一个指针变量
    p = head; //将头指针赋值给p
    if (p == NULL) //判断链表是否为空
    {
        printf("\t\t\t*       暂无商品信息！         *\n");
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t按任意键返回主菜单...");
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
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     商品信息保存成功！        *\n");
        printf("\t\t\t*********************************\n");
    }
}

//从文件读取商品信息函数
void load()
{
    FILE* fp; //定义一个文件指针变量
    fp = fopen("goods.txt", "r"); //以只读模式打开一个名为goods.txt的文本文件
    if (fp == NULL) //判断文件是否打开成功
    {
        printf("\t\t\t*       文件打开失败！         *\n");
        return; //返回主函数
    }
    Goods* p, * q; //定义两个指针变量
    p = (Goods*)malloc(sizeof(Goods)); //动态分配内存空间
    if (p == NULL) //判断内存是否分配成功
    {
        printf("\t\t\t*       内存分配失败！         *\n");
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
            printf("\t\t\t*       内存分配失败！         *\n");
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
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        退出系统界面           *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
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
    printf("\t\t\t*       感谢您使用本系统！      *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t按任意键退出...");
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
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        购物系统主菜单         *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    //显示不同的功能选项
    printf("\t\t\t*       1.购买商品              *\n");
    printf("\t\t\t*       2.打开购物车            *\n");
    printf("\t\t\t*       0.退出系统              *\n");
    printf("\t\t\t*       ");
    scanf("%d", &choice); //输入用户选择
    switch (choice) //根据用户选择执行相应的操作
    {
    case 1: //购买商品
        customer_buy(); //调用购买商品函数
        break;
    case 2: //打开购物车
        customer_cart(); //调用统计商品信息函数
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
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*          购买商品界面         *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    Cart* p1, * q1; //定义两个指针变量
    p1 = (Cart*)malloc(sizeof(Cart)); //动态分配内存空间
    if (p1 == NULL) //判断内存是否分配成功
    {
        printf("\t\t\t*       内存分配失败！         *\n");
        exit(1); //退出程序
    }
    int id; // 定义要购买的商品编号变量
    int buy_number;
    Goods* p; // 定义一个商品指针
    printf("请输入要购买的商品的编号：\n");
    scanf("%d", &id); // 获取用户输入的商品编号
    p = head; // 从头指针开始遍历商品链表
    while (p != NULL) { // 如果链表不为空
        if (p->id == id) { // 如果找到了相同编号的商品，提示原来的信息并获取新的信息
            printf("商品信息如下：\n");
            printf("编号：%d\n", p->id);
            printf("名称：%s\n", p->name);
            printf("价格：%lf\n", p->price);

            printf("输入购买数量:");
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
                    printf("\t\t\t*********************************\n");
                    printf("\t\t\t*       加入购物车成功！        *\n");
                    printf("\t\t\t*********************************\n");
                    sleep(1);
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
                    printf("\t\t\t*********************************\n");
                    printf("\t\t\t*       加入购物车成功！        *\n");
                    printf("\t\t\t*********************************\n");
                    printf("\t\t按任意键返回购物系统主菜单...");
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
    printf("没有找到该编号的商品，无法购买！\n"); // 如果没有找到相同编号的商品，提示错误信息并返回


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
        int choose;
        scanf("%d", &choose);
        if (choose == 1) {
            printf("\t\t结账成功!");
            save();
            exit(0);
        }
    }
}

