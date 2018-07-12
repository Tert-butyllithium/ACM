#include <iostream>
#include <cstring>
#define ls l,m,rt<<1  
#define rs m+1,r,rt<<1|1  
#define maxn 100007
int Sum[maxn<<2],Add[maxn<<2];//Sum��ͣ�AddΪ������   

//PushUp�������½ڵ���Ϣ �����������  
void PushUp(int rt){Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];}  
//Build��������   
void Build(int l,int r,int rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���  
    if(l==r) {//������Ҷ�ڵ�   
        Sum[rt]=1;//��������ֵ   
        return;  
    }  
    int m=(l+r)>>1;  
    //���ҵݹ�   
    Build(l,m,rt<<1);  
    Build(m+1,r,rt<<1|1);  
    //������Ϣ   
    PushUp(rt);  
}  

void PushDown(int rt,int ln,int rn){  
    //ln,rnΪ��������������������������   
    if(Add[rt]){  
        //���Ʊ��   
        Add[rt<<1]=Add[rt];  
        Add[rt<<1|1]=Add[rt];  
        //�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ   
        Sum[rt<<1]=Add[rt]*ln;  
        Sum[rt<<1|1]=Add[rt]*rn;  
        //������ڵ���   
        Add[rt]=0;  
    }  
}  

void Update(int L,int R,int C,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���   
    if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]����   
        Sum[rt]=C*(r-l+1);//�������ֺͣ����ϱ�����ȷ  
        Add[rt]=C;//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������  
        return ;   
    }  
    int m=(l+r)>>1;  
    PushDown(rt,m-l+1,r-m);//���Ʊ��  
    //�����ж�����������[L,R]���޽������н����ŵݹ�   
    if(L <= m) Update(L,R,C,l,m,rt<<1);  
    if(R >  m) Update(L,R,C,m+1,r,rt<<1|1);   
    PushUp(rt);//���±��ڵ���Ϣ   
}


int main(int argc, char const *argv[])
{
    int round;
    int t = 1;
    scanf("%d", &round);
    while (round--)
    {
        int n, o;
        memset(Sum, 0, sizeof(Sum));
        memset(Add, 0, sizeof(Add));
        scanf("%d%d", &n, &o);
        Build(1, n, 1);
        while (o--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Update(a, b, c, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n",t++,Sum[1]);
    }
    return 0;
}


