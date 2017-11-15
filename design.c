#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct date{
    int year;
    int month;
    int day;};
typedef struct Equ{
    char num[10];
    char kind[12];
    char name[18];
    long price;
    struct date buy_time;
    char lab[8];
    struct Equ*next;
}Equ,*link;
void Input_FrKey(link);
void Read_File(link);
void Updata_Infor(link);
void Insert_Device(link);
void Delete_Device(link);
void Modify_Device(link);
void Search_Infor(link);
void Search_ByName(link);
void Search_ByNum(link);
void Count_Infor(link);
void Count_ByKind(link);
void Count_ByData(link);
void Count_ByLab(link);
void printf_Display(link);
void Save_File(link);

//1
int main()
{   
    system("sl -F");
    system("clear");
    link head = (link)malloc(sizeof(Equ));
    int i=1,choice=-1;
    Read_File(head);    
    while(i!=0&&choice!=0)
    {
    system("clear");
	printf("                                                                            \n");
        printf("\t\t\t\t\t\t\t\t|----------------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                    请输入选项编号(0——5):                 |\n");
        printf("\t\t\t\t\t\t\t\t|----------------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                       1————添加设备信息                  |\n");
        printf("\t\t\t\t\t\t\t\t|                       2————修改设备信息                  |\n");
	printf("\t\t\t\t\t\t\t\t|                       3————设备查询                      |\n");
        printf("\t\t\t\t\t\t\t\t|                       4————查看设备                      |\n");
	printf("\t\t\t\t\t\t\t\t|                       5————设备分类统计                  |\n");
        printf("\t\t\t\t\t\t\t\t|                       0————退出系统                      |\n");
	printf("\t\t\t\t\t\t\t\t|----------------------------------------------------------|\n");
        printf("                                                                            \n");
    do
    {
	printf("\n请输入选项编号(1——5): ");
        scanf("%d",&choice);
	switch(choice)
	{
	    case 1:Input_FrKey(head);break;
	    case 2:Updata_Infor(head);break;
	    case 3:Search_Infor(head);break;
	    case 4:printf_Display(head);break;
	    case 5:Count_Infor(head);break;
	    case 0:break;
	}
    }while(choice<0||choice>6);
    }
    if(i!=0)
    printf("\n\n---以上信息已保存!-(文件名infor.txt)---\n");
}    
   
   
   
//2数据录入
void Input_FrKey(link head)
{
    link L,p;
    int flag=1;
    char s[10];
    L=head;
    while(flag)
    {
	printf("\n输入设备编号(以#结束);");
	scanf("%s",s);
        if(strcmp(s,"#")!=0)
	{
	p=(link)malloc(sizeof(Equ));
	strcpy(p->num,s);
	printf("输入设备分类:");
        scanf("%s",&p->kind);
	printf("输入设备名称:");
        scanf("%s",&p->name);
	printf("输入设备价格:");
        scanf("%ld",&p->price);
	printf("输入购买日期(yyyy-mm-dd):");
	scanf("%d-%d-%d",&p->buy_time.year,&p->buy_time.month,&p->buy_time.day);
	getchar();
        printf("输入设备是否报废(Y/N):");
	scanf("%s",p->lab);
//	if(lab==Y||lab==y){
//	printf("输入报废日期(yyyy-mm-dd):");
//	scanf("%d-%d-%d",&p->buy_ btime.year,&p->buy_time.bmonth,&p->buy_time.bday);
//	}
        L->next=p;
	L=p;
	}
        else
        {flag=0;L->next=NULL;1;}
    } 
}


//数据导入
void Read_File(link head)
{
    FILE*fp;
    link L,s;
    int flag=1,i=0;
    head=(link)malloc(sizeof(Equ));
    head->next=NULL;
    L=head;
    if((fp=fopen("info.txt","rb"))==NULL)
    {
	printf("\n********暂时还没有任何设备信息，按任意键进入主菜单选择设备信息的录入!*********");  
	return;
    } 
    while(flag==1)
    {
	s=(link)malloc(sizeof(Equ));
	if(fread(s,sizeof(Equ),1,fp)!=1)
	{
	    if(i==0)
	    {
		printf("\n\t  文件读取错误!");
		getchar();
		break;
	    } 
	    else
	    {
		printf("\n\t  文件读取成功!");
		break;
	    }
	} 
	else
	{L->next=s;L=s;i=1;  /*说明文件读取成功*/} 
    } 
    fclose(fp);
} 


//更新操作
void Updata_Infor(link head)
{
    int choice;
    do
    {
	system("clear");
	printf("\t\t\t\t\t\t\t\t********************更新设备信息********************\n");
        printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|               请输入选项编号(0——3):              |\n");
        printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                 1————添加设备信息                |\n");
        printf("\t\t\t\t\t\t\t\t|                 2————删除设备信息                |\n");
	printf("\t\t\t\t\t\t\t\t|                 3————修改设备信息                |\n");
        printf("\t\t\t\t\t\t\t\t|                 0————返回主菜单                  |\n");
	printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
        printf("                                                                    \n");
        do
        {
            printf("请选择(0一3):");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:Insert_Device(head);break;
            case 2:Delete_Device(head);break;
            case 3:Modify_Device(head);break;
            case 0:break;
            }
        }while(choice<0||choice>3);
    }while(choice!=0);
}

/*添加数据*/
void Insert_Device(link head)
{
    link p;
    int flag=1;
    char choice;
    printf("\n\t\t\t\t\t\t\t\t\t\t\t****************添加一种新设备信息****************\n");
    while(flag)
    {
	p=(link)malloc(sizeof(Equ));
	printf("输入设备编号: ");
	scanf("%s",&p->num);
	getchar();
	printf("输入设备分类: ");
	scanf("%s",&p->kind);
	printf("输入设备名称：");
	scanf("%s",&p->name);
	printf("输入设备价格：");
	scanf("%ld",&p->price);
	printf("输入购买日期(yyyy-mm-dd):");
	scanf("%d-%d-%d",&p->buy_time.year,&p->buy_time.month,&p->buy_time.day);
	getchar();
	printf("输入设备是否报废(Y/N):");
	scanf("%s",p->lab);
	p->next=head->next;
	head->next=p;
	printf("\n要继续添加吗?(Y/others)");
	getchar();
	scanf("%c",&choice);
	if(choice=='Y'||choice=='y')
	{printf("继续添加!\n");flag=1;}
	else flag=0;
    }
    printf("\t添加信息后结果如下:\n");
    printf_Display(head);
//    Save_File(head);
}
/*6删除操作*/
void Delete_Device(link head)
{
    link r,s;
    s=head;
    char l[10],ch;
    int flag,n;
    do
    {
	n=0;             /*n用来控制结束语句*/
	printf("\n\t\t\t\t\t\t\t\t*****************删除一种设备信息*****************\n");
	printf("请输入要删除的设备编号：");
	scanf("%s",l);
	while(s->next!=NULL)
	{
	    r=s;s=s->next;
	    if(strcmp(s->num,l)==0)
	    {
		n=1;
		printf("已找到次设备信息!\n");
		r->next=s->next;
		free(s);
		printf("已删除该设备信息!\n");break;

	    }
	}if(n==0)
	printf("不存在该设备信息!\n");
	printf("\n要继续删除吗?(Y/Other):");
        getchar(); scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
        {flag=1;printf("继续删除!\n");}
        else flag=0;
    }while(flag==1);
    printf("\t删除信息后结果如下:\n  "); 
    printf_Display(head);
    //Save_File(head);
}

//7修改操作
void Modify_Device(link head)
{
    system("clear");
    int choice,flag,n,t=0;
    char l[10],ch,r;
    link s;
    s=head;
    do {
	n=0;
	printf("\n\t\t\t\t\t\t\t\t******************修改一种设备信息*******************\n");
	printf("请输入要修改设备的编号");
	scanf("%s",l);
	while(s->next!=NULL)
	{
	    s=s->next;
	    if(strcmp(s->num,l)==0)
	    {
		n=1;
		printf("存在和已找到此设备信息！该设备信息如下：");
		do
		{
		    if(t!=0)
			printf("\n\n\n********修改这种设备后的信息********\n");
			printf("\n设备编号--设备分类--设备名称--价格（元）--购买时间（年-月-日）--设备是否报废(Y/N)\n") ;
		        printf("%s\t%6s\t%6s\t%81d\t%d-%d-%d\t%6s\n",s->num,s->kind,s->name,s->price,s->buy_time.year,s->buy_time.month,s->buy_time.day,s->lab);

			printf("\t\t\t\t\t\t\t\t******************你想修改哪一项*******************\n");
		        printf("\t\t\t\t\t\t\t\t|-------------------------------------------------|\n");
			printf("\t\t\t\t\t\t\t\t|                请输入选项编号(0——5):            |\n");
		        printf("\t\t\t\t\t\t\t\t|-------------------------------------------------|\n");
			printf("\t\t\t\t\t\t\t\t|                   1————设备编号                 |\n");
		        printf("\t\t\t\t\t\t\t\t|                   2————设备分类                 |\n");
			printf("\t\t\t\t\t\t\t\t|                   3————设备名称                 |\n");
    			printf("\t\t\t\t\t\t\t\t|                   4————设备价格                 |\n");
    			printf("\t\t\t\t\t\t\t\t|                   5————设备购入日期             |\n");
			printf("\t\t\t\t\t\t\t\t|                   6————设备是否报废             |\n");
		        printf("\t\t\t\t\t\t\t\t|                   0————不修改此设备信息         |\n");
			printf("\t\t\t\t\t\t\t\t|-------------------------------------------------|\n");
		        printf("                                                                   \n");
		    do{
		        printf("\n请选择（0-5）：");
			scanf("%d",&choice);
			getchar();
			switch(choice)
			{
			    case 1:printf("\n输入修改后的设备编号：");
				   scanf("%s",&s->num);break;
			    case 2:printf("\n输入修改后的设备分类：");
				   scanf("%s",&s->kind);break;
			    case 3:printf("\n输入修改后的设备名称：");
				   scanf("%s",&s->name);break;
			    case 4:printf("\n输入修改后的设价格：");
				   scanf("%1d",&s->price);break;
			    case 5:printf("\n输入修改后的设备购买日期（yyy-mm-dd)：");
				   scanf("%d-%d-%d",&s->buy_time.year,&s->buy_time.month,&s->buy_time.day);break;
			    case 6:printf("\n输入修改后的设备是否报废(Y/N)：");
				   scanf("%s",&s->lab);break;
			    case 0:return;
			}
		      }while(choice<0||choice>6);
			    printf("\n\t\t\t\t\t\t\t\t******************修改这种设备的信息******************\n");
			    printf("\n设备编号--设备分类--设备名称--价格（元）--购买时间（年-月-日）--设备是否报废(Y/N)\n") ;
			    printf("%s\t%6s\t\t%6s\t%8ld\t%d-%d-%d\t%6s\n",s->num,s->kind,s->name,s->price,s->buy_time.year,s->buy_time.month,s->buy_time.day,s->lab);
			    printf("\n要继续修改本设备其他信息吗？（Y/Others）：");
			    getchar();
			    scanf("%c",&r);
			    if(r=='y'||r=='Y')
			    {
			    t=1;printf("继续修改本设备其他信息!\n");
			    }
			    else t=0;
		}while(t==1);
	    } 
	}
	if(n==0)  printf("不存在该设备信息!\n");
//	printf("\n要继续修改其它设备的信息吗？（Y/Others）：");
//	getchar();
//	scanf("%c",&ch);
//	if(ch=='y'||ch=='Y')
//	{flag=1;printf("继续修改!\n");}
//	else flag=0;
    }while(flag==1);
//	    Save_File(head);
}

//8查询操作
void Search_Infor(link head)
{
    int choice;
    do
    {
	system("clear");
	printf("\t\t\t\t\t\t\t\t********************查询设备信息********************\n");
        printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|               请输入选项编号(0——2):              |\n");
	printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                1————按设备编号查询               |\n");
	printf("\t\t\t\t\t\t\t\t|                2————按设备名称查询               |\n");
	printf("\t\t\t\t\t\t\t\t|                0————返回主菜单                   |\n");
	printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("                                                                    \n");
    do
    {
	printf("请选择（0-2）:");
        scanf("%d",&choice);
	switch(choice)
	{
	    case 1: Search_ByNum(head); break;
            case 2: Search_ByName(head); break;
	    case 0:  break;
	}   
    }
    while(choice<0||choice>6);
    }
    while(choice!=0);
}

//10按名称查询
void Search_ByName(link head)
{
    link s;
    char l[18],ch;
    int n,flag,t;
    do
    {
        s=head;
        n=0;t=1;    /*用来控制打印顶端说明语句,n用来控制结束语句*/
        printf("\n\n\t\t\t\t\t\t\t\t*****************按名称查询设备信息*****************\n");
        printf("请输入要查询的设备名称:");
        scanf("%s",l);
        while(s->next!=NULL)
        {
            s=s->next;
            if(strcmp(s->name,l)==0)
            {
                n=1;
                if(t!=0)
                {
                    printf("已找到此设备信息!相关信息如下:");
                    printf("\n设备编号——设备分类——设备名称——价格(元)——购买时间(年-月-日)——设备是否报废(Y/N)\n");t=0;
                }
                printf("%s\t%6s\t   %6s\t %8ld\t %d-%d-%d\t  %6s\n",s->num,s->kind,s->name,s->price,s->buy_time.year,s->buy_time.month,s->buy_time.day,s->lab);
            }
        }
        if(n==0)   printf("\t\t不存在该设备信息!\n");
        printf("\n要继续查询吗？(Y/Others):");
        getchar();scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        {flag=1;printf("继续查询!");}
        else flag=0;
    }while(flag==1);
    printf("\n按任意键返回上级菜单!");
}


//11按编号查询
void Search_ByNum(link head)
{
    link s;
    char l[10],ch;
    int n,flag,t;
    do
    {
        s=head;
        n=0;t=1;    /*用来控制打印顶端说明语句,n用来控制结束语句*/
        printf("\n\n\t\t\t\t\t\t\t\t*****************按编号查询设备信息*****************\n");
        printf("请输入要查询的设备编号:");
        scanf("%s",l);
        while(s->next!=NULL)
        {
            s=s->next;
            if(strcmp(s->num,l)==0)
            {
                n=1;
                if(t!=0)
                {
                    printf("已找到此设备信息!相关信息如下:");
                    printf("\n设备编号——设备分类——设备名称——价格(元)——购买时间(年-月-日)——设备是否报废(Y/N)\n");t=0;
                }
                printf("%s\t%6s\t   %6s\t%8ld\t %d-%d-%d\t  %6s\n",s->num,s->kind,s->name,s->price,s->buy_time.year,s->buy_time.month,s->buy_time.day,s->lab);
            }
        }
        if(n==0)   printf("\t\t不存在该设备信息!\n");
        printf("\n要继续查询吗？(Y/Others):");
        getchar();
	scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        {flag=1;printf("继续查询!");}
        else flag=0;
    }while(flag==1);
    getchar();
    printf("\n按任意键返回上级菜单!");
}


//统计操作
void Count_Infor(link head)
{
    int choice;
    do
    {
	system("clear");
	printf("\t\t\t\t\t\t\t\t********************统计设备信息********************\n");
        printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                请输入选项编号(0——3):             |\n");
	printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t\t|                 1————按设备种类统计              |\n");
	printf("\t\t\t\t\t\t\t\t|                 2————按日期统计                  |\n");
	printf("\t\t\t\t\t\t\t\t|                 3————按是否报废统计              |\n");
	printf("\t\t\t\t\t\t\t\t|                 0————返回主菜单                  |\n");
	printf("\t\t\t\t\t\t\t\t|--------------------------------------------------|\n");
	printf("                                                    \n");
	do{
	    printf("请选择（0-3）:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
		case 1: Count_ByKind(head); break;
		case 2: Count_ByData(head); break;
		case 3: Count_ByLab(head); break;
		case 0:  break;
	    }
	  }
	    while(choice<0||choice>6);
    }   
    while(choice!=0);
}

//按设备种类统计
void Count_ByKind(link head)
{
    link s;
    char l[12],ch;
    int i,flag,t;
    do 
    {
	s=head;i=0;t=1;
	printf("\n\n请输入要统计的设备分类：");
        scanf("%s",l);
	while(s->next!=NULL)
	{
	    s=s->next;
	    if(strcmp(s->kind,l)==0)
	    {
		i++;
		if(t!=0)
		{printf("\n设备编号-——设备分类——设备名称——价格（元）——购买时间（年-月-日）——设备是否报废(Y/N)\n");t=0;   /* 用t来控制顶端说明语句的打印*/}
		printf("%s\t%6s\t   %6s\t%8ld\t %d-% d-%d\t      %6s\n",s->num,s->kind, s->name, s->price, s->buy_time.year ,s->buy_time.month,s->buy_time.day ,s->lab);
	    }
	}
	printf("\n\n该类设备总类为%d台.\n",i);
	printf("\n要继续统计吗？(Y/others):");
	getchar();
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
	    flag=1;  
	    printf("请继续统计！");
	}
	else flag=0;
    } 
    while(flag==1);
    printf("\n请按任意键返回上级菜单！\n");
} 
 
//按日期统计
void Count_ByData(link head)
{
    link s;
    int a,b,c;
    char ch;
    int i,j,flag,t;
    do 
    {
	s=head;i=0,t=1;
	printf("\n\n请输入要统计的设备日期：");
	scanf("%d-%d-%d",&a,&b,&c);
	while(s->next != NULL)
	{
	    s=s->next;
	    if(a==s->buy_time.year && b==s->buy_time.month && c==s->buy_time.day)
	    {
		i++;
		if(t!=0)
		{printf("\n设备编号-——设备分类——设备名称——价格（元）——购买时间（年-月-日）——设备是否报废(Y/N)\n");} 
		printf("%s\t%6s\t   %6s\t%8ld\t %d-% d-%d\t      %6s\n",s->num,s->kind, s->name, s->price, s->buy_time.year ,s->buy_time.month,s->buy_time.day ,s->lab);
	    }
	} 
	printf("\n\n该类设备总类为%d台.\n",i);
	printf("\n要继续统计吗？(Y/others):");
	getchar();
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
	    flag=1;  
	    printf("请继续统计！");
	}
	else flag=0;
    } 
    while(flag==1);
    printf("\n请按任意键返回上级菜单！");
	getchar();
} 

//按是否报废统计
void Count_ByLab(link head)
{
    link s;
    char l[12],ch;
    int i,flag,t;
    do 
    {
	s=head;i=0;t=1;
	printf("\n\n请输入要统计的设备是否报废(Y/N)：");
        scanf("%s",l);
	while(s->next!=NULL)
	{
	    s=s->next;
	    if(strcmp(s->lab,l)==0)
	    {
		i++;
		if(t!=0)
		{printf("\n设备编号-——设备分类——设备名称——价格（元）——购买时间（年-月-日）——设备是否报废(Y/N)\n");t=0;   /* 用t来控制顶端说明语句的打印*/}
		printf("%s\t%6s\t   %6s\t%8ld\t %d-% d-%d\t      %6s\n",s->num,s->kind, s->name, s->price, s->buy_time.year ,s->buy_time.month,s->buy_time.day ,s->lab);
	    }
	} 
	printf("\n\n该类设备总类为%d台.\n",i);
	printf("\n要继续统计吗？(Y/others):");
	getchar();
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
	    flag=1;  
	    printf("请继续统计！");
	}
	else flag=0;
    } 
    while(flag==1);
    printf("\n请按任意键返回上级菜单！");
} 

//输出设备信息列表
void printf_Display(link head)
{   
    link s;
    s = head;
    if(s->next==NULL)
    {
        printf("没有设备，请先录入设备！");
        return;
    }
    s = s->next;
    printf("===========================================================================\n");
    printf(" 编号\t种类\t名称\t价格\t购入日期\t是否报废(Y/N)\n");
    while(s)
    {
	printf("%s\t%s\t%s\t%ld\t%d-%d-%d\t\t%s\n",s->num,s->kind, s->name, s->price, s->buy_time.year ,s->buy_time.month,s->buy_time.day ,s->lab);
        s = s->next;
    }
    printf("===========================================================================\n");
}

//将链表输入到文件
void Save_File(link head)
{
    FILE *fp=fopen("info.txt","w");
    link s;
    s = head->next;
    while(s)
    {
        fprintf(fp,"%s\n",s->num);
        fprintf(fp,"%s\n",s->kind);
        fprintf(fp,"%s\n",s->name);
        fprintf(fp,"%s\n",s->price);
        fprintf(fp,"%s\n",s->buy_time.year);
        fprintf(fp,"%s\n",s->buy_time.month);
        fprintf(fp,"%s\n",s->buy_time.day);
        fprintf(fp,"%s\n",s->lab);
        //printf("%d %s %s %s %s ",current->num,current->name,current->model,current->factory,current->buy_date);
        s = s->next;
    }
    fclose(fp);
}
