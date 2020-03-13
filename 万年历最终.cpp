#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>

typedef struct Memday       //�ṹ���趨�ڼ��յĴ洢��ʽ 
{
	int m;
	int	d;
	char name[5];
}Memday;
Memday mem[20];
char weekdays[][7]={"������","����һ","���ڶ�","������","������","������","������"};
char month[][12]={"һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����"};
int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31,};
//������׼�����ı��еĽڼ��ն��� 
void festval_txt()
{
	int i;
	FILE *jp;
	jp=fopen("d:\\�ڼ���.txt","r");
	if(jp==0)
	{printf("���ļ�ʧ��\n");
	    exit(0);
	}
	for(i=0;i<=20;i++)
	 fscanf(jp,"%d %d %s",&mem[i].m,&mem[i].d,&mem[i].name);
}
//�ж�ĳ���Ƿ��ǽ��գ����ǣ����ý��������±귵�� 
int festval(int month,int day,int year) 
{
	int i;
	for(i=0;i<=20;i++)
	{
		if(year>1948&&mem[i].m==month&&mem[i].d==day)
           break;
	}	
	if(i<=20)
	 return i;
    else
     return 30;
}
// ��ӡ������������д��ָ���ı��� 
int print(int weekday,int flag,int year)
{
	int i,j,k,n,m,festval_number;
	FILE *fp;
	int *q,*p;
	monthday[1]+=flag;
	fp=fopen("D:\\����.txt","a+");
	if(fp==0)
	{printf("���ļ�ʧ��\n");
	    exit(0);
	}
	for(i=0;i<6;i++)         //������������һ��������������� 
	{
		int month1[6][7]={0},month2[6][7]={0};
	    q=&month1[0][weekday];
		for(j=1;j<=monthday[2*i];j++,q++)
		{
		    *q=j;
		}
		weekday=(weekday+monthday[2*i])%7;
		p=&month2[0][weekday];
		for(k=1;k<=monthday[2*i+1];k++,p++)
		{
			*p=k;
		}
		weekday=(weekday+monthday[2*i+1])%7;
		printf("\t\t");
		fputs("\t\t",fp);
		printf("    ");
		fputs("    ",fp);
        printf("%s",month[2*i]);
        fprintf(fp,"%s",month[2*i],1,0);
	    printf("\t\t\t\t\t\t\t");
	    fputs("\t\t\t\t\t\t\t",fp);
	    printf("%s",month[2*i+1]);
	    fprintf(fp,"%s",month[2*i+1],1,0);
	    printf("\n");
	    fputs("\n",fp);
	    printf(" =================================================");
	    fputs(" =================================================",fp);
	    printf("\t");
	    fputs("\t",fp);
	    printf(" =================================================");
	    fputs(" =================================================",fp);
	    printf("\n");
	    fputs("\n",fp);
	    printf("   Sun    Mon    Tue    Wed    Thu    Fri    Sat ");
	    fputs("   Sun    Mon    Tue    Wed    Thu    Fri  02  Sat ",fp);
	    printf("\t");
	    fputs("\t",fp);
	    printf("   Sun    Mon    Tue    Wed    Thu    Fri    Sat ");
	    fputs("   Sun    Mon    Tue    Wed    Thu    Fri    Sat ",fp);
	    printf("\n");
	    fputs("\n",fp);
	    printf(" -------------------------------------------------");
	    fputs(" -------------------------------------------------",fp);
	    printf("\t");
	    fputs("\t",fp);
        printf(" -------------------------------------------------");
        fputs(" -------------------------------------------------",fp);
        printf("\n");
        fputs("\n",fp);
		for(n=0;n<6;n++)          //n����һ���µ����� ,ÿ���´�ӡ�����������Ϊ����
		{
		    for(m=0;m<7;m++)           //m����һ���µ������������쵽������
		    {
		    	if(month1[n][m]==0)          //ĳһ�еĵ�һ���·ݵ����
		    	  {
		    	  	printf("       ");
		    	    fputs("       ",fp);
				  }
		    	else
		    	{
		    		festval_number=festval(2*i+1,month1[n][m],year);       //���ж���һ���Ƿ�Ϊ�ڼ��� �����ǣ�����ڼ�������
		    		if(festval_number<20)
		    		{
		    		    printf("%7s",mem[festval_number].name);
		    		    fprintf(fp,"%7s",mem[festval_number].name,1,0);	
					} 
		    		else                    
		    		{
		    		    printf("%5d  ",month1[n][m]);
		    		    fprintf(fp,"%5d  ",month1[n][m],1,0);	
					} 
				}
			}
			printf("\t");
			fputs("\t",fp);
			for(m=0;m<7;m++)                     //ĳһ�еĵڶ����·ݵ����
		    {
		    	if(month2[n][m]==0)                   
		    	  {
		    	  	printf("       ");
		    	    fputs("       ",fp);
				  }
		    	else
		    	  {
		    		festval_number=festval(2*i+2,month2[n][m],year);
		    		if(festval_number<20)
		    		{
		    		   printf("%7s",mem[festval_number].name);
		    		   fprintf(fp,"%7s",mem[festval_number].name,1,0);	
					}
		    		else
		    		{
		    		   printf("%5d  ",month2[n][m]);
		    		   fprintf(fp,"%5d  ",month2[n][m],1,0);	
					} 
				 }
			}
		   	printf("\n");
		   	fputs("\n",fp);
		}
		printf("\n");
		fputs("\n",fp);
	} 
	fclose(fp);
}
//�ж��ǲ�������
int judge_year(int year) 
{
	int k=0;
	if(year%400==0||(year%4==0&&year%100!=0))
	  k=1;
	return k;
}
//��ӡ���
int yearnumber(int year) 
{   
    FILE *fp;
    fp=fopen("D:\\����.txt","w+");
    if(fp==0)
	{printf("���ļ�ʧ��\n");
	    exit(0);
	}
    char number0[][8]={"  *****","  *   *","  *   *","  *   *","  *****"};
    char number1[][8]={"     **","     **","     **","     **","     **"};
    char number2[][8]={"  *****","      *","  *****","  *    ","  *****"};
    char number3[][8]={"  *****","      *","  *****","      *","  *****"};
    char number4[][8]={"  *   *","  *   *","  *****","      *","      *"};
    char number5[][8]={"  *****","  *    ","  *****","      *","  *****"};
    char number6[][8]={"  *****","  *    ","  *****","  *   *","  *****"};
    char number7[][8]={"  *****","      *","      *","      *","      *"};
    char number8[][8]={"  *****","  *   *","  *****","  *   *","  *****"};
    char number9[][8]={"  *****","  *   *","  *****","      *","  *****"};
	    int i,j,n,k;
	    printf("\n");
	for(i=0;i<5;i++)
	{
	   int m=1000;
	   printf("\t\t\t\t      ");
	   fputs("\t\t\t\t      ",fp);
	   for(j=0;j<4;j++,m/=10)
	   {
	   n=year/m%10;
       switch(n)
         {
       	    case 0:printf("%s",number0[i]);fprintf(fp,"%s",number0[i],1,0);break;
       	    case 1:printf("%s",number1[i]);fprintf(fp,"%s",number1[i],1,0);break;
       		case 2:printf("%s",number2[i]);fprintf(fp,"%s",number2[i],1,0);break;
       		case 3:printf("%s",number3[i]);fprintf(fp,"%s",number3[i],1,0);break;
       		case 4:printf("%s",number4[i]);fprintf(fp,"%s",number4[i],1,0);break;
       		case 5:printf("%s",number5[i]);fprintf(fp,"%s",number5[i],1,0);break;
       		case 6:printf("%s",number6[i]);fprintf(fp,"%s",number6[i],1,0);break;
       	    case 7:printf("%s",number7[i]);fprintf(fp,"%s",number7[i],1,0);break;
       		case 8:printf("%s",number8[i]);fprintf(fp,"%s",number8[i],1,0);break;
       		case 9:printf("%s",number9[i]);fprintf(fp,"%s",number9[i],1,0);break;
	     }
       }
       printf("\n");
       fputs("\n",fp);
	}
	fclose(fp);
}
//������ݣ��������ֻ�����ݴ���9999�������С��0���ᱨ��
int putin_year()
{
    int i,k,len,m=1,year=0;
	char s[20];
	printf("\t\t\t\t\t>>��������Ҫ���ҵ����:");
	getchar();
	gets(s);
	while(s[i]!='\0')
	{
		len=strlen(s);
		while(s[i]<'0'||s[i]>'9'||len>4)
	    {
	    	i=0;
	    	printf("\n");
	    	printf("\t\t\t\t\t>>������ݴ�������������:");
	    	gets(s);
	    	len=strlen(s);
		}
		i++;
	}
	for(k=len;k>0;k--,m=m*10)
	year+=(s[k-1]-48)*m;
    return year;
}
//���ò��չ�ʽ����ĳһ���1��1�������ڼ�
int week(int year)
{
	int c,y,w,day;
    year-=1;
    c=year/100;
    y=year%100;
    if(year>1582)
       w=c/4-2*c+y+y/4+13*14/5;
    else
       w=y+y/4+c/4-2*c+13*14/5+4;
    if(w>0)
      day=w%7;
    else
      day=w%7+7;
      printf("\n");
    printf("\t\t\t\t\t  %d���1��1����",year+1);
    puts(weekdays[day]);
	return day;
}
//��ȡ��ǰʱ��
void timenow()
{
	 time_t t;
	 struct tm *pt;
	 time(&t);
	 pt=localtime(&t);
	 printf("\n\t\t\t                 ������%d��%d��%d�գ�",pt->tm_year+1900,pt->tm_mon+1,pt->tm_mday);
        puts(weekdays[pt->tm_wday]);
	 printf("\t\t\t                   ��ǰʱ����%dʱ%d��%d��\n",pt->tm_hour,pt->tm_min,pt->tm_sec);
	printf("\n");
}
//�˵� 
int menu()
{
	int choice;
	printf("                                       *****************************\n");
	printf("\n");
	printf("                                              >> 1.������ѯ\n");
	printf("                                              >> 2.��ǰʱ���ѯ\n");
	printf("                                              >> 3.�˳�����\n");
    printf("\n");
	printf("                                       *****************************\n");
	printf("\t\t\t\t\t>>��ѡ��");
	scanf("%d",&choice);
	return choice;
}
//������ 
int main ()
{
    int year,choice=4,day,flag;
    festval_txt();
    printf("\t\t\t\t\t   ��ӭʹ����������ѯϵͳ��"); 
	printf("\n");
    while(choice!=3)
    {
	   choice=menu();
       switch(choice)
       {
           case 1:year=putin_year();
		          day=week(year);
				  yearnumber(year);
				  flag=judge_year(year);
				  print(day,flag,year);
				  break;
    	   case 2:timenow();break;
    	   case 3:break;
		   default :printf("\t\t\t\t\t>>��Чѡ��������ѡ��\n") ; 
	   }
    }

    return 0;
}
// 