#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6
#include <windows.h>
#include <mmsystem.h>
#pragma comment(Lib,"winmm.lib")

int main()
{
    PlaySound(TEXT("sounds\\��������.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
    int i,j,k,temp;          //j����ʱ��������i�����ӣ��������Ӻøж�-10�á�
    int choice;             //�ʵ۵�ѡ��
    int searchIndex = -1;  // �������ɾ��Ԫ�ص��±�
    int count = 5;        //��ǰδ�����乬����������
    char meperorName[20];//�ʵ۵����ţ�ʹ���ַ������ʾ�ַ���
    char tempName[20];  //���������ʱ�ַ������ַ�����
    char names[MAX][20]={"����","����","��֪����","��ʩ","��˿��"};//������������
    char levelNames[5][10]={"����","����","����","�ʹ���","�ʺ�"};
    //��������,�������ÿ�����ӵļ�������ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ������
    int levels[MAX]={1,2,0,0,4,-1};
    //lovesÿ������Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ���ÿ�����Ӻøжȶ�Ϊ100
    int loves[MAX]={100,100,100,100,100,-1};
    printf("������ʵ۵����ţ�");
    scanf("%s",meperorName);//¼���ַ���������Ҫ&
    for(k = 0;k <10;k++)
    {
    printf("/******************************************");
    printf("\n���Դ��룺�鿴��ǰ������״̬�� \n");
    printf("%-10s\t����\t�øж�\n","����");
    for(i = 0;i < count;i++)
    {
        printf("%-10s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    printf("��%d��",k+1);

    printf("�ʵۡ�%s������,�������࣬�����˳���\n",meperorName);
    printf("1���ʵ���ּѡ����\t(���ӹ���)\n");
    printf("2�����Ƴ���\t\t(�޸�״̬����)\n");
    printf("3�������乬\t\t(ɾ������)\n");
    printf("4�������ټ�����ȥС�������������\n");
    printf("������ѡ��:");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:PlaySound(TEXT("sounds\\ѡ��.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
               //�ʵ���ּѡ����\t(���ӹ���)
              //1����������Ԫ�أ�names��leves��loves��
              //2������ǰ��Ҫ�ж�������û�пռ�
              if(count < MAX)//�����ǰ����������С��ϵͳ���ֵ
              {
                  //ִ����Ӳ���
                  printf("���������������:");
                  scanf("%s",names[count]);//����count��Ԫ�ص�״̬��ʼ��
                  levels[count] = 0;
                  loves[count] = 100;
                  count++;                //�������countһ��Ҫ�Ӽ�
              }
              else
              {
                  printf("����Ҫע������ѽ�����Ѿ�����Ϊ���ˣ�\n");
              }
        break;
        case 2:PlaySound(TEXT("sounds\\����.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //���Ƴ���\t\t(�޸�״̬����)
            //1���ҵ�Ҫ���ҵ����ӵ��±�����
            //2���޸�������ӵ�״̬   �øж�+10������+1���������߼��Ͳ���������
            //3���޸��������ӵ�״̬   �øж�-10
            //δ֧�����������ڵ����������������
            printf("���£����������Ҫ������������䣺");
            scanf("%s",tempName);
            //�ַ����Ĳ���strcmp.��Ҫ����<string.h>
            //strcmp(tempName,"abc")  0-�����ַ������     1-ǰһ�����ں�һ��      -1-ǰһ��С�ں�һ��
            for(i = 0;i < count;i++)
            {
                  if(strcmp(tempName,names[i])==0)//������������պõ��������е�ĳ������
                  {
                      loves[i] +=10;
                      if(levels[i] >= 4)
                        levels[i] = 4;
                      else
                      levels[i] +=1;
                      for(j = 0;j < i;j++)
                      {
                          loves[j] -= 10;
                      }
                      for(j= i+1;j <count;j++)
                      {
                          loves[j] -= 10;
                      }
                  }

            }
            printf("δ�ҵ���\n");
        break;
        case 3:PlaySound(TEXT("sounds\\�乬.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //�����乬\t\t(ɾ������
               //1������
               //2������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
               //3������--
               //4���޸��������ӵ�״̬���øж�+20
            printf("���£�������Ҫ�����乬��������䣺");
            scanf("%s",tempName);
            //ѭ������
            for(i = 0;i < count;i++)
            {
                if(strcmp(tempName,names[i])==0)//������������պõ��������е�ĳ������
                {//��¼���±�
                    searchIndex = i;
            break;
                }
            }
            if(searchIndex == -1)//����ǳ�ֵ��ʾû���ҵ�
            {
                printf("�龪һ�������˴����乬\n");
            }
            else
            {
                for(i = searchIndex;i <= count-1;i++)
                {
                    //names[i] = names[i+1];��Ϊ���ַ�����C���Բ�֧�������ֱ�Ӹ�ֵ����ʹ��strcpy
                    strcpy(names[i],names[i+1]);
                    loves[i] = loves[i+1];
                    levels[i] = levels[i+1];
                }
                count--;
                for (i = 0;i < count;i++)
                {
                    loves[i] +=20;
                }

            }

        break;
        case 4:PlaySound(TEXT("sounds\\һЦ���.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //�����ټ�����ȥС�������������
               //1������
               //2�����Ӻøж�
               printf("������Ҫ�����ټ��İ��������䣺");
               scanf("%s",tempName);
               for(i = 0;i < count;i++)
               {
                   if(strcmp(tempName,names[i])==0)
                    loves[i] +=10;
               }
        break;
        default:
            printf("����Ϸ��,�������ٴ�ȷ�ϣ�\n");
    }
    printf("%-10s\t����\t�øж�\n","����");
    for(i = 0;i < count - 1;i++)
    {
        for(j = 0;j < count -i - 1;j++)
        {
            if(loves[j] < loves[j+1])
            {
              temp = loves[j];
              loves[j] = loves[j+1];
              loves[j+1] = temp;
              temp = levels[j];
              levels[j] = levels[j+1];
              levels[j+1] = temp;
              strcpy(tempName,names[j]);
              strcpy(names[j],names[j+1]);
              strcpy(names[j+1],tempName);
            }
        }
        printf("%-10s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    }
    return 0;
}
