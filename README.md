# supermarket system of management
# 实训报告
# 一、需求分析，描述问题
&emsp;&emsp;对于超市管理者来说，大量复杂的销售、进货、报损管理、供应商管理等难于通过传统的方法进行管理。小型超市管理系统正是对上述的问题而开发的，通过计算机系统来管理货品销售与进货的情况，可以解决大量商品信息的查询和管理，便于更好的进行商品管理，同时也为销售员提供方便。

&emsp;&emsp;超市随着市场经济和现代化信息技术的发展，不可必要的被卷入信息现代化的大潮之中，如何使用现代化的工具，使企业和经营者个人在最小的投入下获取回报。因此，在超市管理中引进现代化的办公软件，就成为时下最好的解决办法。使用软件办公，不仅能使经营者的劳力资本减少，同时能够使超市的管理更规范更合理，解决了超市中用于管理进出货以及购买、库存等众多繁琐、工作量巨大从而到导致耗费人员过多，超市经营紊乱等众多问题.

&emsp;&emsp;长期以来。超市业务一直使用着简单的人工管理。超市经营物品的采购、库存、销售以及核算的手工信息管理使得工作量巨大、服务质量差、工作效率低。同时对市场的反馈不能及时的处理，从而导致销售与市场脱节。最终的结果只能使超市在经营中处于不利的地位。在此基础上，我们开发了这套系统。目的就是为了解决超市管理的紊乱，使得在超市的日常经营中及销售中，能够有迹可循，随时跟踪市场，而且减少了不必要的劳力成本。

&emsp;&emsp;随着管理信息系统理论的实践进一步的发展，随着信息系统的优越性的进一步体现，现代信息化的管理系统代替传统的简单的计算机操作方式是社会发展的一个必然趋势。管理信息系统是对一个组织进行全面管理的人机系统，综合运用计算机技术、信息技术、管理技术和决策技术，与现代化的管理思想方法和手段结合起来，辅助管理人员进行管理和决策。超市管理信息系统就是融合现代商业经营思想和先进的信息处理技术为一体的管理信息系统

# 二、总体设计

## 系统功能
本系统完成超市商品销售，存储与会员信息的管理工作，系统功能如下表1所示
系统|模块|功能
---|:-:|:-:
&emsp;|商品管理|商品入库、出库、修改管理
超市管理系统|收银功能|商品购物车、结账、购买功能
&emsp;|会员功能|会员的注册、登录、找回密码功能

## 总体结构
``````                
                            |录入商品信息
            |超市管理系统————|展示商品信息
            |               |统计商品信息             
            |               |修改商品信息
功能选择页面——
            |           |购买商品
            |收银系统————|打开购物车 |注册会员
                        |会员———————|登陆会员
                                    |找回密码
``````                              
# 三、详细设计

## ————超市管理系统界面

该系统需要以管理员身份进行登录，主要实现商品信息录入，显示，修改以及统计功能。

### 1、录入商品信息
代码描述：首先对其录入的商品进行判断，如果已经存在则询问是否录入，如果不存在，则进行录入，直到不再录入，最终保存到文件中
<center> 判断是否存在 </center>
~ reid : reid:要录入商品的ID

~ temp:用于判断要录入商品类别是否已经存在: 0表示存在，1表示不存在
功能：遍历链表，验证要录入的商品ID是否已经存在

```void input()
{
    system("cls"); //清屏
    system("color f5");
	int reid;
   int temp = 1;   //表示当前状态
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
}
```

<center>不存在的情况</center>

11 – 20行：代码用于提示用户输入，来完善商品信息，并存储到临时的p中

31 – 34行：如果链表为空，把p设置为head，如果不为空，则把p插到链表的最后面

36行：存储商品信息

37– 48行：询问用户是否继续录入，如果继续，递归调用input()函数，如果停止，则返回管理主菜单

```
1、	if (temp == 1) {//验证重复id
2、	
3、	        Goods* p, * q; //定义两个指针变量
4、	        p = (Goods*)malloc(sizeof(Goods)); //动态分配内存空间
5、	        if (p == NULL) //判断内存是否分配成功
6、	        {
7、	            printf("\t\t\t\t\t*       内存分配失败！         *\n");
8、	            exit(1); //退出程序
9、	        }
10、	        p->id = reid;
11、	        printf("\t\t\t\t\t*       请输入商品名字：        *\n");
12、	        printf("\t\t\t\t\t        ");
13、	        scanf("%s", p->name); //输入商品名称
14、	        printf("\t\t\t\t\t*       请输入商品单价：        *\n");
15、	        printf("\t\t\t\t\t        ");
16、	        scanf("%f", &p->price); //输入商品单价
17、	        printf("\t\t\t\t\t*       请输入商品库存：        *\n");
18、	        printf("\t\t\t\t\t        ");
19、	        scanf("%d", &p->stock); //输入商品库存
20、	        p->next = NULL; //初始化指针域为NULL
21、	        if (head == NULL) //判断链表是否为空
22、	        {
23、	            head = p; //将p赋值给头指针
24、	        }
25、	        else //链表不为空
26、	        {
27、	            q = head; //将头指针赋值给q
28、	            while (q->next != NULL) //遍历链表，找到最后一个节点
29、	            {
30、	                q = q->next;
31、	            }
32、	            q->next = p; //将p插入到最后一个节点的后面
33、	        }
34、	        count++; //商品数量加1
35、	        save();
36、	        printf("\t\t\t\t\t*                               *\n");
37、	        printf("\t\t\t\t\t*********************************\n");
38、	        printf("\t\t\t\t\t*     商品信息录入成功！        *\n");
39、	        printf("\t\t\t\t\t*********************************\n");
40、	        printf("\t\t\t\t\t*     请选择是否继续录入        *\n");
41、	        printf("\t\t\t\t\t*     1:继续录入      *\n");
42、	        printf("\t\t\t\t\t*     2:返回管理系统主菜单 *\n");
43、	        int flag = 0;
44、	        scanf("%d", &flag);
45、	        if (flag == 1) {
46、	            input();
47、	        }
48、	    }
```

<center>存在的情况：</center>
```
询问用户是否继续重复录入，如果决定重复录入，则调用input(),否则返回主管理菜单
else {
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     商品信息录入重复！        *\n");
        printf("\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t*     请选择是否继续录入        *\n");
        printf("\t\t\t\t\t*     1:继续录入      *\n");
        printf("\t\t\t\t\t*     2:返回管理系统主菜单 *\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
}
```

<center>save函数的实现:</center>
```
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
        return; //返回主菜单函数
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
```

### 2、展示商品信息
代码描述
在main函数中已经提前调用过了load()函数用于加载数据到链表中，只需要遍历链表，并设置好输出格式，就可以显示所有商品的数据.

<center>main函数中的流程：</center>
```
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
```

<center>Display函数的实现</center>
首先会判断链表是否为空，如果为空则会返回主管理菜单，如果不为空，则会遍历链表输出商品信息

在main函数中已经提前载入了商品的数据，所以，接下来可以直接去使用链表来对商品信息进行显示
```
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
```

<center>load函数的实现：</center>
```
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
```

### 3、统计商品信息
该函数首先进行清屏操作，保证页面整洁。

随后通过定义指针变量p，并将头指针赋值给p，来判断链表是否为空，即库中商品信息是否为空，如果为空，则输出“暂无商品信息！”提示，反之则定义变量num（商品总数），value（商品总价值），average（商品平均单价），遍历链表，通过累加及相关运算，获取商品总数，商品总价值，商品平均单价信息，并使用printf函数进行显示，最后返回主菜单。
```
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
```

### 4、修改商品信息
该函数首先定义整形变量id（商品编号变量），商品指针*p，随后调用display（）函数对库中商品信息进行显示，随后读入用户输入的商品编号，遍历数组，判断是否存在该商品，如果存在，则寻找到相应编号商品，进行相应信息（商品名称，商品价格，商品数量）的修改；否则则输出"没有找到该编号的商品，无法修改！"提示。
```
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
```




## ————购物主菜单界面

### 1、 层次结构

整体系统分为两个部分：
销售管理模块：负责处理顾客的购物、结账等操作。
库存管理模块：负责监控和调整商品的库存量，生成库存报表。

而销售管理界面则包含：购买商品将商品加入购物车，查看商品并结账，会员登陆功能。

这里主要讲解购物主菜单界面。

### 2、数据结构
购物车中商品信息采用链表数据结构来进行存储。

    typedef struct cart//该结构体为存储购物车中的信息 
    {
        int id; //商品编号
        char name[20]; //商品名称
        float price; //商品单价
        int number;//购物的数量 
        struct cart* next; //指向下一个购物节点 
    }Cart;

而另一种方式则是采用结构体数组

    typedef struct cart//该结构体为存储购物车中的信息 
    {
        int id; //商品编号
        char name[20]; //商品名称
        float price; //商品单价
        int number;//购物的数量 
    }Cart;

    Cart[100]

链表通过指针在不连续的内存空间进行跳转，以此实现可动态扩展的特性。

链表不可随机访问，只能顺序访问；单链表只可单向顺序访问；链表的增删一般会比顺序表写开销小，读开销基本相当，但是改查的读开销远大于顺序表；

#### 链表vs数组

##### 链表的优点：
- 插入和删除元素时只需要调整指针，时间复杂度为O(1)。
- 链表的大小不固定，可以动态地增加或减少元素。
##### 链表的缺点：
- 随机访问元素的时间复杂度为O(n)，因为需要从头开始遍历。
- 在内存中不连续存储，需要更多的内存空间和管理成本。
- 不支持直接通过下标操作元素。

##### 数组的优点：
- 随机访问元素非常快，时间复杂度为O(1)。
- 在内存中连续存储，易于分配和管理。
- 可以直接通过下标操作数组元素，使用方便。
##### 数组的缺点：
- 插入和删除元素时需要移动大量元素，时间复杂度为O(n)。
- 数组的大小固定，需要预先分配足够的内存空间，不够灵活。

对于实现购物车所用的数据结构，顾客由于需要对购物车中商品进行频繁调整，并且不同的顾客购物的数量有很大不同，我们使用链表来存储购物信息。

### 3.功能实现
在主界面选择进入购物界面后，调用shop_menu()函数

    void shop_menu() {
        int choice; //定义用户选择变量
        system("cls"); //清屏
        printf("\n\n\n");
        printf("\t\t\t\t\t\t   WELCOMOE!\n");
        printf("\t    /\\__/\\          \t\t*********************************\t\t    / \\__/\\          \n");
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
这段代码使用switch语句，通过输入的不同数字调用对应的函数。

##### 若输入1
调用customer_buy()函数

    void customer_buy(){
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
                        cart_head = p1; //将p1赋值给头指针

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
                        q1->next = p1; //将p1插入到最后一个节点的后面

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
函数会先调用display()展示商品，等待顾客输入购买商品编号，若编号不存在，则会提示并退出；若库存不足，也会提示并退出。若输入正确的编号并数量满足库存，则将输入的商品编号对应的商品信息加入购物车中，并减少库存。

##### 若输入2
调用customer_cart()函数

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
函数会先遍历链表并展示购物车中已有的商品信息，并计算出总价格，若是会员身份则会打折。

## ————会员部分

### 1、需求分析
会员模块
会员制消费能促进顾客的购物积极性，巩固超市的老客户，同时给予会员优惠，达到双赢的目的。负责管理会员信息，同时进行会员信息推送。

### 2、详细设计

函数中的调用关系
在shop_menu函数中让用户作出选择后被调用，主体部分如下
```
void shop_menu() {
    
    printf("\t\t\t\t\t*        1.购买商品             *\n");
    printf("\t\t\t\t\t*        2.打开购物车           *\n");
    if (!whethermember) {
        printf("\t\t\t\t\t*        3.会员登陆             *\n");
    }
    printf("\t\t\t\t\t*        0.退出系统             *\n");
    printf("\t\t\t\t\t        ");
    printf("\n\t\t\t\t\t 请选择：");
    scanf("%d", &choice);    //输入用户选择
system("cls");

    case 3:             //会员登陆
        vip_login();     //调用会员登陆
        break;
}
```

会员部分：
```
typedef struct The_members
{
    char name[15];//姓名为字符串 
    long phone; //电话号码为长整型 
    char id[11]; //账号 
    char key[20]; //密码 
}members;                                 //会员部分结构数组
```

首先列出会员部分的功能，利用set3()函数让用户作出选择，在会员界面期间可以随时返回
```
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
```

<center>主要有三个功能</center>
1、注册会员：对应函数registermembers()。对于还未注册的会员进行注册，创建文件members.txt进行会员信息的储存，期间对于已注册的会员进行查重，避免出现用户名重叠的情况。需要获取会员的姓名，联系方式，账号等，同时需要进行二次确认密码，在确认密码注册成功创建文件phone.txt向用户的手机发送注册成功的信息，同时开启信息推送。
```
void registermembers()
{
   
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
    fflush(stdin);  //清空输入缓存的函数，在输入字符之前调用它可以清除之前未读取的字符。
    Sleep(500);   //Sleep是指输出的间隔，控制为500ms 
    fp = fopen("members.txt", "a");           //创建一个文件
    fp = fopen("members.txt", "r");
    fread(&b, sizeof(struct The_members), 1, fp); //读出数据存放的地址 b，从b中读取一个大小为一个结构体的内容  
    printf("\t请输入姓名：");             //提示用户注册信息
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
            rewind(stdin);         //重新指向文件的开头
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
            ph = fopen("phone.txt", "w");   //建立一个手机的文件用于会员通知
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
```

```
2、登陆会员：对应函数MemberInput_login()。一个简单的登陆界面，登陆界面时有一个韩式progress进行进度条的显示。登录界面主要分辨用户名是否存在，输入的密码是否正确，在进行信息确认后开启会员模式，此后购买商品进行打折处理。同时进行手机上登陆成功通知，以免他人操作，同时推送超市广告.
void  MemberInput_login()
{
    members a, b;  //定义结构体The_members别名

    FILE* fp;   //文件 
    int i = 0;

    system("cls");         //清屏操作

    system("color f5");       //调整背景色和字体

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
            Sleep(1000);      //对于进度条模仿
            fflush(stdin);    //清除缓存区输入

            printf("\n\n\t\t\t\t\t\t登 录 成 功，即 刻 享 受 会 员 权 益 !");
            FILE* ph;
            ph = fopen("phone.txt", "a");
            fprintf(ph, "\n【钱多多超市】您好，尊敬的会员%s，您已成功登录，衷心祝愿您有一个良好的购物体验。若非本人操作请及时联系客服处理\n", a.id);

            fprintf(ph, "\n【钱多多超市】坤哥哥玩偶，11.99元/件起;香蕉君手办,29.99/件起；500g鸭脖，18.99/袋起。晚8点线上开售。速戳https://m.tb.cn/h.5bystcP?tk=r2w5dtmg68M.退订回T");
            fclose(ph);
            Sleep(1000);
            system("cls");
            printf("您 好，尊 敬 的 会 员%s\n", a.id);
            whethermember = 1;           //表明会员已登录，后续购物享受打折优惠
            return;
        }
        else
        {

            printf("密码错误！");
            printf("\n\n\n");
            printf("\t\t\t\t   │============================================│\n");
            printf("\t\t\t\t   │ 请输入密码：                         │\n");
            printf("\t\t\t\t   │============================================│\n");

            cursor(50, 13);   //调整输入的位置，便于美观
            scanf("%s", &a.key);

        }


    } while (strcmp(a.key, b.key) == 0);

}
```

3、忘记密码：对应函数memberfind()。对于忘记了密码的用户，进行身份信息确认，包含账户，姓名，联系方式等，在确认完毕后生成四位随机数验证码发送到用户手机上，在用户输入正确验证码过后告知用户会员密码，并让用户返回重新登陆。
```
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
            else g[i] = third;         //生成一个四位随机数

    }
    FILE* ph;
    ph = fopen("phone.txt", "a");//追加一个账号         
    fprintf(ph, "\n【钱多多超市】您好，尊敬的用户%s，本次身份验证的验证码为：%s。若非本人操作请及时联系客服处理\n", a.id, g);   //将验证码信息发送到用户的手机上
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
    printf("您 的 密 码 为 ：%s, 请 记 住 它 哟 ~\n", b.key);  //在验证成功后将密码输出



    Sleep(3000);
    system("pause");
    system("cls");
}
```

4、特殊cursor函数，获得当前输出窗口的句柄，便于界面的美观
```
void cursor(int x, int y)
{
    COORD pos;          //COORD是Windows API中定义的一种结构 
    HANDLE h;           //HANDLE:句柄
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //获得当前输出窗口的句柄
    SetConsoleCursorPosition(h, pos);    //控制光标的位置
}
```

5、最后在用户成功登录会员后，此后的购物进行打折处理。

### 3、用户手册
您可选择是否使用会员界面，若您有会员，可进行登陆后享受在本超市购物打折处理，若没有会员则可按照提示进行注册。全程依照您的选择，没有强制要求。如果您忘了密码，也可利用手机验证码进行密码找回，会员的一些通知我们也会利用手机通知您。


## 四、调试与测试

## 五、测试用例设计

## 六、测试结果

## 七、用户手册
