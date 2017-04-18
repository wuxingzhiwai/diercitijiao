#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6
#include <windows.h>
#include <mmsystem.h>
#pragma comment(Lib,"winmm.lib")

int main()
{
    PlaySound(TEXT("sounds\\背景音乐.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
    int i,j,k,temp;          //j翻牌时，翻到第i个妃子，其他妃子好感度-10用。
    int choice;             //皇帝的选择
    int searchIndex = -1;  // 用来存放删除元素的下标
    int count = 5;        //当前未打入冷宫的嫔妃个数
    char meperorName[20];//皇帝的名号，使用字符数组表示字符串
    char tempName[20];  //用来存放临时字符串的字符数组
    char names[MAX][20]={"貂蝉","杨玉环","不知火舞","西施","亚丝娜"};//贵妃姓名数组
    char levelNames[5][10]={"贵人","嫔妃","贵妃","皇贵妃","皇后"};
    //级别数组,用来存放每个妃子的级别数，每个数组元素对应每个妃子的当前级别数
    int levels[MAX]={1,2,0,0,4,-1};
    //loves每个数组元素对应每个妃子的好感度，初始情况每个妃子好感度都为100
    int loves[MAX]={100,100,100,100,100,-1};
    printf("请输入皇帝的名号：");
    scanf("%s",meperorName);//录入字符串，不需要&
    for(k = 0;k <10;k++)
    {
    printf("/******************************************");
    printf("\n测试代码：查看当前嫔妃的状态： \n");
    printf("%-10s\t级别\t好感度\n","姓名");
    for(i = 0;i < count;i++)
    {
        printf("%-10s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }
    printf("第%d天",k+1);

    printf("皇帝《%s》驾临,有事启奏，无事退朝！\n",meperorName);
    printf("1、皇帝下旨选妃：\t(增加功能)\n");
    printf("2、翻牌宠幸\t\t(修改状态功能)\n");
    printf("3、打入冷宫\t\t(删除功能)\n");
    printf("4、单独召见爱妃去小树林做纯洁的事\n");
    printf("陛下请选择:");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:PlaySound(TEXT("sounds\\选妃.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
               //皇帝下旨选妃：\t(增加功能)
              //1、增加数组元素（names、leves、loves）
              //2、增加前需要判断数组有没有空间
              if(count < MAX)//如果当前的妃子数量小于系统最大值
              {
                  //执行添加操作
                  printf("请输入娘娘的名讳:");
                  scanf("%s",names[count]);//将第count个元素的状态初始化
                  levels[count] = 0;
                  loves[count] = 100;
                  count++;                //增加完后count一定要加加
              }
              else
              {
                  printf("陛下要注意龙体呀，后宫已经人满为患了！\n");
              }
        break;
        case 2:PlaySound(TEXT("sounds\\翻牌.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //翻牌宠幸\t\t(修改状态功能)
            //1、找到要宠幸的妃子的下标索引
            //2、修改这个妃子的状态   好感度+10，级别+1，如果是最高级就不在升级。
            //3、修改其他妃子的状态   好感度-10
            //未支持姓名不存在的情况，请自行完善
            printf("陛下，请输入今天要翻牌娘娘的名讳：");
            scanf("%s",tempName);
            //字符串的查找strcmp.需要引入<string.h>
            //strcmp(tempName,"abc")  0-两个字符串相等     1-前一个大于后一个      -1-前一个小于后一个
            for(i = 0;i < count;i++)
            {
                  if(strcmp(tempName,names[i])==0)//如果输入姓名刚好等于数组中的某个姓名
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
            printf("未找到！\n");
        break;
        case 3:PlaySound(TEXT("sounds\\冷宫.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //打入冷宫\t\t(删除功能
               //1、查找
               //2、后面一个元素赋值给前面一个元素
               //3、总数--
               //4、修改其他妃子的状态，好感度+20
            printf("陛下，请输入要打入冷宫娘娘的名讳：");
            scanf("%s",tempName);
            //循环查找
            for(i = 0;i < count;i++)
            {
                if(strcmp(tempName,names[i])==0)//如果输入姓名刚好等于数组中的某个姓名
                {//记录下下标
                    searchIndex = i;
            break;
                }
            }
            if(searchIndex == -1)//如果是初值表示没有找到
            {
                printf("虚惊一场，无人打入冷宫\n");
            }
            else
            {
                for(i = searchIndex;i <= count-1;i++)
                {
                    //names[i] = names[i+1];因为是字符串，C语言不支持数组的直接赋值，须使用strcpy
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
        case 4:PlaySound(TEXT("sounds\\一笑倾城.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
            //单独召见爱妃去小树林做纯洁的事
               //1、查找
               //2、增加好感度
               printf("请输入要单独召见的爱妃的名讳：");
               scanf("%s",tempName);
               for(i = 0;i < count;i++)
               {
                   if(strcmp(tempName,names[i])==0)
                    loves[i] +=10;
               }
        break;
        default:
            printf("君无戏言,陛下请再次确认！\n");
    }
    printf("%-10s\t级别\t好感度\n","姓名");
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
