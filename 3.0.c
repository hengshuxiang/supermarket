#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

char userName[50] = { "cangkuguanliyuan" };
char userPwd[16] = { "123456789" };
int whethermember = 0;//��Ա��ݱ�ʶ

typedef struct The_members
{
    char name[15];//����Ϊ�ַ��� 
    long phone; //�绰����Ϊ������ 
    char id[11]; //�˺� 
    char key[20]; //���� 
}members;                                 //��Ա���ֽṹ����


typedef struct goods
{
    int id; //��Ʒ���
    char name[20]; //��Ʒ����
    float price; //��Ʒ����
    int stock; //��Ʒ���
    struct goods* next; //ָ����һ���ڵ��ָ��
}Goods;

typedef struct cart//�ýṹ��Ϊ�洢���ﳵ�е���Ϣ 
{
    int id; //��Ʒ���
    char name[20]; //��Ʒ����
    float price; //��Ʒ����
    int number;//��������� 
    struct cart* next; //ָ����һ������ڵ� 
}Cart;


//����ȫ�ֱ���
Goods* head = NULL; //����ͷָ�룬ָ������ĵ�һ���ڵ�

Cart* cart_head = NULL;//����ͷָ�룬ָ������ĵ�һ���ڵ㣨���ﳵ�ã�

int count = 0; //������Ʒ����

//��������ԭ��
void welcome(); //��ӭ���溯��
void main_menu(); //���˵�����
void shop_menu();//����˵�����
void input(); //¼����Ʒ��Ϣ����
void display(); //��ʾ��Ʒ��Ϣ����
void statistics(); //ͳ����Ʒ��Ϣ����
void save(); //������Ʒ��Ϣ���ļ�����
void load(); //���ļ���ȡ��Ʒ��Ϣ����
void exit_system(); //�˳�ϵͳ����
void modify();//�޸���Ʒ����
int login();//����Ա��½ϵͳ 

//��������ԭ�ͣ����ﳵ�ã�
void customer_buy();
void customer_cart();
void exit_system();
void checkout();
//��Աϵͳ
void vip_login();
void set3();
void registermembers();//ע���˺�
void MemberInput_login();//��½�˺�
void memberfind();//�һ�����
void cursor(int x, int y);
void progress();
//������
int main()
{
    load(); //���ô��ļ���ȡ��Ʒ��Ϣ����
    int choose;
    while (1) {
        welcome(); //���û�ӭ���溯��
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            while (1) {
                main_menu(); //�������˵�����
            }
            break;
        case 2:
            while (1) {
                shop_menu(); //�������˵�����
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
    printf("\t\t*     ��ӭʹ�ó��й���ϵͳ      *\n");
    printf("\t\t*                               *\n");
    printf("\t\t*   ����1������Ʒ�������˵�...  *\n");
    printf("\t\t*   ����2���빺�����˵�...      *\n");
    printf("\t\t*                               *\n");
    printf("\t\t*********************************\n");
    printf("\n\n\n\n");

}


int login() {
    char Name[50];
    char Password[16];
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*       ����Ա��¼              *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t�������˺ţ�");
    scanf("%s", Name);
    printf("\t\t\t���������룺");
    scanf("%s", Password);
    if (strcmp(Name, userName) == 0 && strcmp(Password, userPwd) == 0) {
        system("cls");
        printf("\n\n");
        printf("\t\t\t       ��½�ɹ���              \n");
        Sleep(1000);
        system("cls");
        return 0;
    }
    else {
        printf("\t\t\t*       ��½ʧ�ܣ�              *\n");
        int flag = 0;
        printf("\t\t\t*       ��ѡ���Ƿ������¼      *\n");
        printf("\t\t\t*       1��������¼             *\n");
        printf("\t\t\t*       0���˳�ϵͳ             *\n");
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
//���˵�����
void main_menu()
{
    int choice; //�����û�ѡ�����
    system("cls"); //����
    while (login());
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        ���й���ϵͳ���˵�     *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    //��ʾ��ͬ�Ĺ���ѡ���¼�롢��ʾ����ѯ���޸ġ�ɾ��������ͳ�ơ����桢��ȡ���˳���
    printf("\t\t\t*       1.¼����Ʒ��Ϣ          *\n");
    printf("\t\t\t*       2.��ʾ��Ʒ��Ϣ          *\n");
    printf("\t\t\t*       3.ͳ����Ʒ��Ϣ          *\n");
    printf("\t\t\t*       4.�޸���Ʒ��Ϣ          *\n");
    printf("\t\t\t*       0.�˳�ϵͳ              *\n");
    printf("\t\t\t*       ");
    scanf("%d", &choice); //�����û�ѡ��
    switch (choice) //�����û�ѡ��ִ����Ӧ�Ĳ���
    {
    case 1: //¼����Ʒ��Ϣ
        input(); //����¼����Ʒ��Ϣ����
        break;
    case 2: //��ʾ��Ʒ��Ϣ
        display(); //������ʾ��Ʒ��Ϣ����
        printf("\t\t��������������˵�...");
        getchar();
        getchar();
        break;
    case 3: //ͳ����Ʒ��Ϣ
        statistics(); //����ͳ����Ʒ��Ϣ����
        break;
    case 4: //ɾ����Ʒ��Ϣ
        modify(); //����ɾ����Ʒ��Ϣ����
        break;
    case 0: //�˳�ϵͳ
        exit_system(); //�����˳�ϵͳ����
        break;
    default: //��Ч��ѡ��
        printf("\t\t\t*     ��Ч��ѡ�����������룡   *\n");
        getchar();
        getchar();
        main_menu(); //���µ������˵�����
    }
}

//¼����Ʒ��Ϣ����
void input()
{
    system("cls"); //����
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        ¼����Ʒ��Ϣ����       *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");

    printf("\t\t\t*       ��������Ʒ��ţ�        *\n");
    printf("\t\t\t        ");
    int reid;
    int temp = 1;
    scanf("%d", &reid); //������Ʒ���
    Goods* pid;
    pid = head;
    while (pid != NULL) //����������ӡÿ���ڵ��������
    {
        if (pid->id == reid) {
            temp = 0;
            break;
        }
        pid = pid->next; //��pָ����һ���ڵ�
    }

    if (temp == 1) {//��֤�ظ�id

        Goods* p, * q; //��������ָ�����
        p = (Goods*)malloc(sizeof(Goods)); //��̬�����ڴ�ռ�
        if (p == NULL) //�ж��ڴ��Ƿ����ɹ�
        {
            printf("\t\t\t*       �ڴ����ʧ�ܣ�         *\n");
            exit(1); //�˳�����
        }
        p->id = reid;
        printf("\t\t\t*       ��������Ʒ���֣�        *\n");
        printf("\t\t\t        ");
        scanf("%s", p->name); //������Ʒ����
        printf("\t\t\t*       ��������Ʒ���ۣ�        *\n");
        printf("\t\t\t        ");
        scanf("%f", &p->price); //������Ʒ����
        printf("\t\t\t*       ��������Ʒ��棺        *\n");
        printf("\t\t\t        ");
        scanf("%d", &p->stock); //������Ʒ���
        p->next = NULL; //��ʼ��ָ����ΪNULL
        if (head == NULL) //�ж������Ƿ�Ϊ��
        {
            head = p; //��p��ֵ��ͷָ��
        }
        else //����Ϊ��
        {
            q = head; //��ͷָ�븳ֵ��q
            while (q->next != NULL) //���������ҵ����һ���ڵ�
            {
                q = q->next;
            }
            q->next = p; //��p���뵽���һ���ڵ�ĺ���
        }
        count++; //��Ʒ������1
        save();
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     ��Ʒ��Ϣ¼��ɹ���        *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     ��ѡ���Ƿ����¼��        *\n");
        printf("\t\t\t*     1:����¼��	 	*\n");
        printf("\t\t\t*     2:���ع���ϵͳ���˵�	*\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
    }
    else {
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     ��Ʒ��Ϣ¼���ظ���        *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     ��ѡ���Ƿ����¼��        *\n");
        printf("\t\t\t*     1:����¼��	 	*\n");
        printf("\t\t\t*     2:���ع���ϵͳ���˵�	*\n");
        int flag = 0;
        scanf("%d", &flag);
        if (flag == 1) {
            input();
        }
    }
}

//��ʾ��Ʒ��Ϣ����
void display()
{
    system("cls"); //����
    printf("\n\n\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    printf("\t*                                ��ʾ��Ʒ��Ϣ����                                       *\n");
    printf("\t*                                                                                       *\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    Goods* p; //����һ��ָ�����
    p = head; //��ͷָ�븳ֵ��p
    if (p == NULL) //�ж������Ƿ�Ϊ��
    {
        printf("\t*       ������Ʒ��Ϣ��                                                                  *\n");
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t��������������˵�...");
        getchar();
        getchar();
        return; //����������
    }
    else //����Ϊ��
    {
        printf("\t*��Ʒ���\t��Ʒ����\t��Ʒ����\t��Ʒ���\t                        *\n");
        while (p != NULL) //����������ӡÿ���ڵ��������
        {
            printf("\t*%d\t\t%8s\t%.2f\t\t%d\t\t\t", p->id, p->name, p->price, p->stock);
            printf("                *\n");
            p = p->next; //��pָ����һ���ڵ�
        }
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");

    }
}


//ͳ����Ʒ��Ϣ����
void statistics()
{
    system("cls"); //����
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        ͳ����Ʒ��Ϣ����       *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    Goods* p; //����һ��ָ�����
    p = head; //��ͷָ�븳ֵ��p
    if (p == NULL) //�ж������Ƿ�Ϊ��
    {
        printf("\t\t\t*       ������Ʒ��Ϣ��         *\n");
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t��������������˵�...");
        getchar();
        getchar();
        return; //����������
    }
    else //����Ϊ��
    {
        int num = 0; //������Ʒ��������
        float value = 0.0; //������Ʒ�ܼ�ֵ����
        float average = 0.0; //������Ʒƽ�����۱���
        while (p != NULL) //���������ۼӸ�������
        {
            num++; //��Ʒ������1
            value += p->price * p->stock; //��Ʒ�ܼ�ֵ���ڵ��۳��Կ��ĺ�
            average += p->price; //��Ʒƽ�����۵��ڸ�����Ʒ���۵ĺ�
            p = p->next; //��pָ����һ���ڵ�
        }
        average /= num; //��Ʒƽ�����۵��ڸ�����Ʒ���۵ĺͳ�����Ʒ����
        printf("\t\t\t       ��Ʒ������%d             \n", num); //��ӡ��Ʒ����
        printf("\t\t\t       ��Ʒ�ܼ�ֵ��%.2f         \n", value); //��ӡ��Ʒ�ܼ�ֵ��������λС��
        printf("\t\t\t       ��Ʒƽ�����ۣ�%.2f       \n", average); //��ӡ��Ʒƽ�����ۣ�������λС��
        printf("\t\t\t*********************************\n");
        printf("\t\t����������ع���ϵͳ���˵�...");
        getchar();
        getchar();
    }
}

//������Ʒ��Ϣ���ļ�����
void save()
{
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*     ������Ʒ��Ϣ����          *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    Goods* p; //����һ��ָ�����
    p = head; //��ͷָ�븳ֵ��p
    if (p == NULL) //�ж������Ƿ�Ϊ��
    {
        printf("\t\t\t*       ������Ʒ��Ϣ��         *\n");
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t��������������˵�...");
        getchar();
        getchar();
        return; //����������
    }
    else //����Ϊ��
    {
        FILE* fp; //����һ���ļ�ָ�����
        fp = fopen("goods.txt", "w"); //��д��ģʽ��һ����Ϊgoods.txt���ı��ļ�������������򴴽�
        if (fp == NULL) //�ж��ļ��Ƿ�򿪳ɹ�
        {
            printf("\t\t\t*       �ļ���ʧ�ܣ�         *\n");
            exit(1); //�˳�����
        }
        while (p != NULL) //����������ÿ���ڵ��������д�뵽�ļ��У�ÿ������֮���ÿո������ÿ���ڵ��û��з�����
        {
            fprintf(fp, "%d %s %.2f %d\n", p->id, p->name, p->price, p->stock);
            p = p->next; //��pָ����һ���ڵ�
        }
        fclose(fp); //�ر��ļ�
        printf("\t\t\t*                               *\n");
        printf("\t\t\t*********************************\n");
        printf("\t\t\t*     ��Ʒ��Ϣ����ɹ���        *\n");
        printf("\t\t\t*********************************\n");
    }
}

//���ļ���ȡ��Ʒ��Ϣ����
void load()
{
    FILE* fp; //����һ���ļ�ָ�����
    fp = fopen("goods.txt", "r"); //��ֻ��ģʽ��һ����Ϊgoods.txt���ı��ļ�
    if (fp == NULL) //�ж��ļ��Ƿ�򿪳ɹ�
    {
        printf("\t\t\t*       �ļ���ʧ�ܣ�         *\n");
        return; //����������
    }
    Goods* p, * q; //��������ָ�����
    p = (Goods*)malloc(sizeof(Goods)); //��̬�����ڴ�ռ�
    if (p == NULL) //�ж��ڴ��Ƿ����ɹ�
    {
        printf("\t\t\t*       �ڴ����ʧ�ܣ�         *\n");
        exit(1); //�˳�����
    }
    while (fscanf(fp, "%d %s %f %d", &p->id, p->name, &p->price, &p->stock) != EOF) //���ļ��ж�ȡÿ���ڵ��������ֱ���ļ�����
    {
        p->next = NULL; //��ʼ��ָ����ΪNULL
        if (head == NULL) //�ж������Ƿ�Ϊ��
        {
            head = p; //��p��ֵ��ͷָ��
        }
        else //����Ϊ��
        {
            q = head; //��ͷָ�븳ֵ��q
            while (q->next != NULL) //���������ҵ����һ���ڵ�
            {
                q = q->next;
            }
            q->next = p; //��p���뵽���һ���ڵ�ĺ���
        }
        count++; //��Ʒ������1
        p = (Goods*)malloc(sizeof(Goods)); //Ϊ��һ���ڵ�����ڴ�ռ�
        if (p == NULL) //�ж��ڴ��Ƿ����ɹ�
        {
            printf("\t\t\t*       �ڴ����ʧ�ܣ�         *\n");
            exit(1); //�˳�����
        }
    }
    fclose(fp); //�ر��ļ�
}


//�˳�ϵͳ����
void exit_system()
{
    save();
    system("cls"); //����
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        �˳�ϵͳ����           *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    Goods* p, * q; //��������ָ�����
    p = head; //��ͷָ�븳ֵ��p
    while (p != NULL) //���������ͷ�ÿ���ڵ���ڴ�ռ�
    {
        q = p->next; //��qָ��p����һ���ڵ�
        free(p); //�ͷ�p��ָ����ڴ�ռ�
        p = q; //��pָ��q
    }
    head = NULL; //��ͷָ����ΪNULL
    count = 0; //����Ʒ������Ϊ0
    printf("\t\t\t*       ��л��ʹ�ñ�ϵͳ��      *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t��������˳�...");
    getchar();
    exit(0);

}


// �޸���Ʒ����
void modify() {
    int id; // ����Ҫ�޸ĵ���Ʒ��ű���
    Goods* p; // ����һ����Ʒָ��
    display();
    printf("������Ҫ�޸ĵ���Ʒ�ı�ţ�\n");
    scanf("%d", &id); // ��ȡ�û��������Ʒ���
    p = head; // ��ͷָ�뿪ʼ������Ʒ����
    while (p != NULL) { // �������Ϊ��
        if (p->id == id) { // ����ҵ�����ͬ��ŵ���Ʒ����ʾԭ������Ϣ����ȡ�µ���Ϣ
            printf("ԭ������Ʒ��Ϣ���£�\n");
            printf("��ţ�%d\n", p->id);
            printf("���ƣ�%s\n", p->name);
            printf("�۸�%lf\n", p->price);
            printf("������%d\n", p->stock);
            printf("�������µ���Ʒ���Ʊ�ţ�\n");
            scanf("%d", &p->id); // ��ȡ�û����������Ʒ����
            printf("�������µ���Ʒ���ƣ�\n");
            scanf("%s", p->name); // ��ȡ�û����������Ʒ����
            printf("�������µ���Ʒ�۸�\n");
            scanf("%f", &p->price); // ��ȡ�û����������Ʒ�۸�
            printf("�������µ���Ʒ������\n");
            scanf("%d", &p->stock); // ��ȡ�û����������Ʒ����
            printf("�޸���Ʒ�ɹ���\n"); // ��ʾ�ɹ���Ϣ
            save();//��������ϱ���
            return;
        }
        p = p->next; // ָ����һ����Ʒ�ڵ�
    }
    printf("û���ҵ��ñ�ŵ���Ʒ���޷��޸ģ�\n"); // ���û���ҵ���ͬ��ŵ���Ʒ����ʾ������Ϣ������
}





void shop_menu() {
    int choice; //�����û�ѡ�����
    system("cls"); //����
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*        ����ϵͳ���˵�         *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    //��ʾ��ͬ�Ĺ���ѡ��
    printf("\t\t\t*       1.������Ʒ              *\n");
    printf("\t\t\t*       2.�򿪹��ﳵ            *\n");
    printf("\t\t\t*       3.��Ա��½              *\n");
    printf("\t\t\t*       0.�˳�ϵͳ              *\n");
    printf("\t\t\t*       ");
    scanf("%d", &choice); //�����û�ѡ��
    switch (choice) //�����û�ѡ��ִ����Ӧ�Ĳ���
    {
    case 1: //������Ʒ
        customer_buy(); //���ù�����Ʒ����
        break;
    case 2: //�򿪹��ﳵ
        customer_cart(); //����ͳ����Ʒ��Ϣ����
        break;
    case 3: //��Ա��½
        vip_login(); //���û�Ա��½
        break;
    case 0: //�˳�ϵͳ
        exit_system(); //�����˳�ϵͳ����
        break;
    default: //��Ч��ѡ��
        printf("\t\t\t*     ��Ч��ѡ�����������룡   *\n");
        getchar();
        getchar();
        shop_menu(); //���µ������˵�����
    }
}

//������Ʒ����
void customer_buy()
{
    display();
    printf("\n\n\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*          ������Ʒ����         *\n");
    printf("\t\t\t*                               *\n");
    printf("\t\t\t*********************************\n");
    printf("\t\t\t*                               *\n");
    Cart* p1, * q1; //��������ָ�����
    p1 = (Cart*)malloc(sizeof(Cart)); //��̬�����ڴ�ռ�
    if (p1 == NULL) //�ж��ڴ��Ƿ����ɹ�
    {
        printf("\t\t\t*       �ڴ����ʧ�ܣ�         *\n");
        exit(1); //�˳�����
    }
    int id; // ����Ҫ�������Ʒ��ű���
    int buy_number;
    Goods* p; // ����һ����Ʒָ��
    printf("������Ҫ�������Ʒ�ı�ţ�\n");
    scanf("%d", &id); // ��ȡ�û��������Ʒ���
    p = head; // ��ͷָ�뿪ʼ������Ʒ����
    while (p != NULL) { // �������Ϊ��
        if (p->id == id) { // ����ҵ�����ͬ��ŵ���Ʒ����ʾԭ������Ϣ����ȡ�µ���Ϣ
            printf("��Ʒ��Ϣ���£�\n");
            printf("��ţ�%d\n", p->id);
            printf("���ƣ�%s\n", p->name);
            printf("�۸�%lf\n", p->price);

            printf("���빺������:");
            scanf("%d", &buy_number);
            if (buy_number <= p->stock) {
                p1->id = p->id;
                strcpy(p1->name, p->name);
                p1->price = p->price;

                p->stock -= buy_number;
                p1->number = buy_number;

                p1->next = NULL; //��ʼ��ָ����ΪNULL
                if (cart_head == NULL) //�ж������Ƿ�Ϊ��
                {
                    cart_head = p1; //��p��ֵ��ͷָ��

                    system("cls");
                    printf("\t\t\t*********************************\n");
                    printf("\t\t\t*       ���빺�ﳵ�ɹ���        *\n");
                    printf("\t\t\t*********************************\n");
                    Sleep(1000);
                    return;
                }
                else //����Ϊ��
                {
                    q1 = cart_head; //��ͷָ�븳ֵ��q
                    while (q1->next != NULL) //���������ҵ����һ���ڵ�
                    {
                        q1 = q1->next;
                    }
                    q1->next = p1; //��p���뵽���һ���ڵ�ĺ���

                    system("cls");
                    printf("\t\t\t*********************************\n");
                    printf("\t\t\t*       ���빺�ﳵ�ɹ���        *\n");
                    printf("\t\t\t*********************************\n");
                    printf("\t\t����������ع���ϵͳ���˵�...");
                    getchar();
                    getchar();
                    return;
                }
            }
            else {
                printf("��治��!�����������");
                getchar();
                getchar();
                return;
            }
        }
        p = p->next; // ָ����һ����Ʒ�ڵ�
    }
    printf("û���ҵ��ñ�ŵ���Ʒ���޷�����\n"); // ���û���ҵ���ͬ��ŵ���Ʒ����ʾ������Ϣ������


}

void checkout() {
    save();
}


void customer_cart() {
    double sum = 0;
    system("cls"); //����
    printf("\n\n\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    printf("\t*                                ��ʾ��Ʒ��Ϣ����                                       *\n");
    printf("\t*                                                                                       *\n");
    printf("\t*****************************************************************************************\n");
    printf("\t*                                                                                       *\n");
    Cart* p1; //����һ��ָ�����
    p1 = cart_head; //��ͷָ�븳ֵ��p
    if (p1 == NULL) //�ж������Ƿ�Ϊ��
    {
        printf("\t*       ������Ʒ��Ϣ��                                                                  *\n");
        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t����������ع���ϵͳ���˵�...");
        getchar();
        getchar();
        return; //����������
    }
    else //����Ϊ��
    {
        printf("\t*��Ʒ���\t��Ʒ����\t��Ʒ����\t��������\t                        *\n");
        while (p1 != NULL) //����������ӡÿ���ڵ��������
        {
            printf("\t*%d\t\t%8s\t%.2f\t\t%d\t\t", p1->id, p1->name, p1->price, p1->number);
            if (strlen(p1->name) < 8) //������Ʒ���Ƶĳ��ȣ����������ʽ
            {
                printf("\t");
            }
            printf("                *\n");
            sum += p1->price * p1->number;
            p1 = p1->next; //��pָ����һ���ڵ�
        }


        printf("\t*                                                                                       *\n");
        printf("\t*****************************************************************************************\n");
        printf("\t\t�ܼ۸�:%.2f\n", sum);
        printf("\t\t����1���ˣ�����0���ع���ϵͳ���˵�...\n");
        int choose;
        scanf("%d", &choose);
        if (choose == 1) {
            printf("\t\t���˳ɹ�!");
            save();
            exit(0);
        }
    }
}










//��Ա����



void vip_login() {
    set3();
}
void set3() {
    int choose;         //�û������ѡ�� 
    int ture = 1;       //ѭ���ж���� 


    while (ture != 0)
    {
        system("color f5");
        printf("\t\t\t\t\t   �q �] % �r               �q ```�r  \n");
        printf("\t\t\t\t\t   (@^o^@) ���л�Ա��¼ϵͳ (��:��)\n");
        printf("\t\t\t\t\t   (~):(~)              (~)v(~) \n");
        printf("%70s", "\t\t������������������������������\n");
        printf("%66s", "[ 1.ע���Ա    ]\n");
        printf("%66s", "[ 2.��½��Ա    ]\n");
        printf("%66s", "[ 3.��������    ]\n");
        printf("%70s", "\t\t������������������������������\n");
        printf("��ѡ��");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            getchar();
            system("cls");
            registermembers();    //ע���˻�
            break;

        case 2:
            progress();     //������ 
            system("cls");
            MemberInput_login();  //��¼�˻�
            getchar();
            ture = 0;
            break;

        case 3:
            getchar();
            memberfind();       //�һ����� 
            break;

        default:
            getchar();
            rewind(stdin);      //������̻��� 
            printf("����������������룡\n");
            system("pause");
            system("cls");
            break;
        }

    }

}

void Membership_File()
{
    FILE* fp;

    if ((fp = fopen("members.txt", "rb")) == NULL)               /*�ж��ļ��Ƿ����*/
    {
        if ((fp = fopen("members.txt", "wb+")) == NULL)          /*��д������*/
        {
            printf("�޷������ļ���\n");
            exit(0);

        }
    }
}


/*-------
 ע���˺�
---------*/

void registermembers()
{
    //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С

    members a, b; //�ṹ�� The_members ����������
    FILE* fp;  //����ͷ�ļ� fp 


    char temp[20];//������룬����ȷ�� 
    int count = 0;
    int flag = 1;
    char memberchoice;
    char signchoice;
    printf("�� �� �� �� �� Ա �� �� y/n \n");
    scanf("%c", &memberchoice);
    if (memberchoice == 'n') {
        printf("�� �� �� �� ע �� �� Ա �� ?  y/n \n");
        getchar();
        scanf("%c", &signchoice);
        if (signchoice == 'y') {
            system("cls");//���� 
            Sleep(800);
            system("color f5");
            printf("                --------------------------\n");
            printf("                    ��ӭ������Աע����棡\n");
            printf("                --------------------------\n");
            fflush(stdin); //������뻺��ĺ������������ַ�֮ǰ�������������֮ǰδ��ȡ���ַ���
            Sleep(500);   //Sleep��ָ����ļ�� 

            fp = fopen("members.txt", "r");

            fread(&b, sizeof(struct The_members), 1, fp); //�������ݴ�ŵĵ�ַ b  

            printf("������������\n");
            scanf("%s", &a.name);


            printf("������绰���룺\n");
            scanf("%ld", &a.phone);

            printf("�������˺ţ��û���)\n");
            scanf("%s", &a.id);

            while (flag)
            {
                if (strcmp(a.id, b.id)) /*������������*/
                {
                    if (!feof(fp))    /*���δ���ļ�β*/
                    {
                        fread(&b, sizeof(struct The_members), 1, fp);
                    }
                    else

                        break;

                }
                else
                {
                    printf("���û������Ѵ��ڣ�������ѡ��\n");

                    getchar();
                    rewind(stdin);
                    Sleep(800);
                    system("cls");

                    return;
                }
            }



            printf("����������\n");
            scanf(" %s", &a.key);

            printf("��ȷ������\n");
            scanf(" %s", &temp);

            do {

                if (!strcmp(a.key, temp))
                {
                    fp = fopen("members.txt", "a");//׷��һ���˺� 

                    fwrite(&a, sizeof(struct The_members), 1, fp);/* a ��д���ļ���ָ�� ����ַ��*/

                    printf("��Աע��ɹ����뷵�ص�¼������е�¼������\n");
                    Sleep(500);
                    fclose(fp);

                    return;
                }
                else
                {
                    printf("�������벻ƥ�䣡���������룡\n");
                    getchar();
                    scanf("%s", &a.key);

                    printf("��ȷ������\n");
                    scanf("%s", &temp);
                }

            } while (1);
        }
        if (memberchoice == 'y') {
            return;
        }

    }
}


/*---------
 ��¼ϵͳ
---------*/

void  MemberInput_login()
{
    members a, b;  //����ṹ��The_members����

    FILE* fp;   //�ļ� 
    int i = 0;

    system("cls");

    system("color f5");

    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t��ӭ������Ա��¼���棡\n");

    Sleep(1500);
    system("cls");//���� 
    Sleep(800);

    fp = fopen("members.txt", "r");

    fread(&b, sizeof(struct The_members), 1, fp); //����һ���ṹ���ַ��� д��b

    printf("\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� �������û�����                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //����д��û���
        {
            break;
        }

        else
        {
            if (fp == NULL)
            {
                printf("�� δ ӵ �� �� Ա ע �� �� Ϣ���� ע ��\n");
                system("pause");
                system("cls");
                set3();
            }


            if (!feof(fp))  //����ļ�û�ж���                            

            {
                fread(&b, sizeof(struct The_members), 1, fp);
                /*�������� b ��ŵĵ�ַλ�ã��ڴ��С��ÿ�ζ�ȡһ�����ݿ� 1 ���Զ��ķ�ʽ���ļ�*/
            }

            else
            {
                printf("�� �� Ա �� �� �� �ڣ��� �� �� ѡ ��\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }

    printf("\n\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� ���������룺                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 8);

    while ((a.key[i] = getch()) != 13)//getch()����ֵ��һ����ֵ���س��ļ�ֵ��13
    {                                   //�����������洢������������Ļ�������* ���������� 
        i++;
        printf("*");//��������
    }
    a.key[i] = '\0';//�����Ļس���ɽ����������飩 
    printf("\n");

    do {

        if (strcmp(a.key, b.key) == 0)            /*�������ƥ��*/

        {
            fclose(fp);

            Sleep(500);
            printf("\n\n\t\t\t\t\t\tVIP��¼������");

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

            printf("\n\n\t\t\t\t\t\t�� ¼ �� ������ �� �� �� �� Ա Ȩ �� !");
            FILE* ph;
            ph = fopen("phone.txt", "a");
            fprintf(ph, "\n���ã��𾴵Ļ�Ա%s�����ѳɹ���¼������ףԸ����һ�����õĹ������顣���Ǳ��˲����뼰ʱ��ϵ�ͷ�����\n", a.id);
            fclose(ph);
            Sleep(1000);
            system("cls");
            printf("�� �ã��� �� �� �� Ա%s\n", a.id);
            whethermember = 1;
            return;
        }
        else
        {

            printf("�������");
            printf("\n\n\n");
            printf("\t\t\t\t   ��============================================��\n");
            printf("\t\t\t\t   �� ���������룺                         ��\n");
            printf("\t\t\t\t   ��============================================��\n");

            cursor(50, 13);
            scanf("%s", &a.key);

        }


    } while (strcmp(a.key, b.key) == 0);

}





/*---------
 �һ�����
----------*/

void memberfind()  //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С
{
    members a, b;//�ṹ�� The_users ����������
    FILE* fp;

    char temp[20];
    //int count = 0;

    printf("�� ӭ �� �� �� �� �� �� �� �� ���� �� �� �� �� Ҫ �� �� �� �� �� �� �� ֤\n");
    Sleep(1000);

    fp = fopen("members.txt", "r");

    fread(&b, sizeof(struct The_members), 1, fp); //����һ���ṹ���ַ��� д��b

    system("cls");
    system("color f5");

    printf("\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� �������˺ţ�                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //����д��û���
        {
            break;
        }

        else
        {
            if (!feof(fp))  //����ļ�û�ж���                            

            {
                fread(&b, sizeof(struct The_members), 1, fp);
                //���ļ��п���һ����СΪstruct The_members������ 
            }

            else
            {
                printf("�� �� �� �� �� �� �� ���� �� �� ѡ �� ��\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }


    printf("\n\n");
    printf("�� �� �� �� ����\n");
    scanf("%s", &a.name);

    do
    {
        if (strcmp(a.name, b.name))
        {
            printf("�� �� �� �� �� �� ���� �� �� �� �� ��\n");
            getchar();
            scanf("%s", &a.name);
        }
    } while (strcmp(a.name, b.name));

    printf("�� �� �� �� �� �� �� ��\n");
    scanf("%ld", &a.phone);

    do {
        if (a.phone != b.phone)
        {
            printf("�� �� �� �� �� �� �� �� ���� �� �� �� �� ��\n");
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
    ph = fopen("phone.txt", "a");//׷��һ���˺�         
    fprintf(ph, "\n���ã��𾴵��û�%s�����������֤����֤��Ϊ��%s�����Ǳ��˲����뼰ʱ��ϵ�ͷ�����\n", a.id, g);
    fclose(ph);
    printf("�� ֤ �� �� �� �� �� �� �� �� �� ��\n");
    printf("�� �� �� �� ֤ �� ��\n");
    scanf("%s", w);
    while (strcmp(g, w))
    {
        printf("�� ֤ �� �� ���� �� �� �� �� \n:");
        scanf("%s", w);
    }
    printf("��֤�ɹ���");
    printf("�� �� �� �� Ϊ ��%s, �� �� ס �� Ӵ ~\n", b.key);



    Sleep(3000);
    system("pause");
    system("cls");
}





void cursor(int x, int y)
{
    COORD pos;          //COORD��Windows API�ж����һ�ֽṹ 
    HANDLE h;           //HANDLE:���
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //��õ�ǰ������ڵľ��
    SetConsoleCursorPosition(h, pos);

}

/*-------
 ������
-------*/

void progress()
{
    int i;
    int j;

    system("cls");

    printf("\n\n\n\n\n\t\t\t\t    \033[0;33;40m     �� �� �� �� ϵ ͳ���� �� �� . . .   \033[0m");

    const char* LastStr = "[--------------------------------------------------] 100%";
    // ��������־�����Ը���"*"����������
    const char ProgressIcon = '*';
    // ����ÿ��5���������ͻ��һ��ע��StepֵҪ��LastStr�е�"-"������ƥ�䣬������˵���100
    const int Step = 2;
    // �ܹ���Ҫ���ٽ��ȱ�־����LastStr��"-"������
    const int IconMaxNum = 50;

    printf("\n\n    \t\t\t\t");
    for (i = 0; i <= 100; ++i)
    {
        // -------------- ��ӡ������ --------------
        printf("<");
        int currentIndex = i / Step;
        for (j = 0; j < IconMaxNum; ++j)
        {
            if (j < currentIndex)
            {
                printf("\033[0;33;1m%c", ProgressIcon); // ��ӡ��������־
            }
            else
            {
                printf(" "); // δ��������ӡ�ո�
            }
        }
        printf("> ");
        // -------- ��ӡ���ֽ��� ----------
        printf("\033[0;35;0m%3d%%", i);
        fflush(stdout);
        // ÿ��100ms��ӡһ�Σ�����ͬʱÿ��100ms���ý��ȼ�1
        Sleep(3 * 10);
        for (j = 0; j < strlen(LastStr); ++j)  //strlen �ַ���������
        {
            printf("\b");               // ��ɾ�ַ��������ֺͽ�����ԭ�ر仯
        }
        fflush(stdout); //������������
    }

    printf("\n\n");
    return;

}