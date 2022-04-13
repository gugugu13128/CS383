#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
struct Book{
    string no;   //8λ���
    string name; //����
    double price;     //�۸�
    bool operator ==(const Book& a)
    {
        return a.name==this->name&&a.no==this->no&&a.price==this->price;
    }
};
bool cmp(Book &a,Book &b)
{
    return a.price>b.price;
}
class sstm//ͼ�����ϵͳ
{
public:
    vector<Book> bks;
    void print();//ȫ����ӡ
    void xprint(int k);//��ӡĳһ��
    void add(int k,Book t);
    void shan(int k);
};
void sstm::xprint(int k)
{
    if(k>=bks.size()||k<0)
        cout<<"-----------û���Ȿ��-----------";
    else
        cout<<"---������"<<bks[k].name<<"---��ţ�"<<bks[k].no<<"---�۸�"<<fixed<<setprecision(2)<<bks[k].price<<"---"<<endl;
}
void sstm::print()
{
    for(int i=0;i<bks.size();i++) xprint(i);
}
void sstm::add(int k,Book t)
{
    bks.insert(bks.begin()+k,t);//��k������T 
}
void sstm::shan(int k)
{
    bks.erase(bks.begin()+k);
}
int main()
{
    sstm test;
    int z=1;
    while(z)
    {
        cout<<"����1-----------------------����ͼ����Ϣ"<<endl;
        cout<<"����2-----------�����ʾͼ���������ͼ��"<<endl;
        cout<<"����3---����ͼ����뵽ͼ�����ָ����λ��"<<endl;
        cout<<"����4---------------------------ɾ��ͼ��"<<endl;
        cout<<"����5-----------------------ͳ��ͼ������"<<endl;
        cout<<"����6-------------------------------ȥ��"<<endl;
        cout<<"����7---------------------�������ͼ��"<<endl;
        cout<<"����8---------------------------�����޸�"<<endl;
        cout<<"����9-----------------��ͼ�鰴�ս�������"<<endl;
        cout<<"����-1----------------------�������ͼ��"<<endl;
        cout<<"����-2--------------------------�û��ֲ�"<<endl; 
        cout<<"����0-------------------------------�˳�"<<endl;
        cin>>z;
        if(z==1)
        {
            double c;
            cout<<"����������������۸����ͼ�飬����0 0 0ʱ�������"<<endl;
            string a,b;
            cin>>a>>b>>c;
            while(a!="0"&&b!="0"&&c!=0)
            {
                Book tmp;
                tmp.name=b;
                tmp.no=a;
                tmp.price=c;
                test.bks.push_back(tmp);//ĩβ���� 
                cin>>a>>b>>c;
            }
        }
        else if(z==2)
        {
            cout<<"-------------------------����"<<test.bks.size()<<"��ͼ��---------------------"<<endl;
            test.print();
        }
        else if(z==3)
        {
            int k;
            double c;
            string a,b;
            cout<<"-------�����������λ�á���š��������۸�-------"<<endl;
            cin>>k>>a>>b>>c;
            if(k>test.bks.size())
            {
                cout<<"---------��Ǹ�����λ�÷Ƿ���-------"<<endl;
                continue;
            }
            Book tmp;
            tmp.name=b;
            tmp.no=a;
            tmp.price=c;
            test.add(k-1,tmp);//k-1������tmp 
            test.print();
        }
        else if(z==4)
        {
            cout<<"--------------����Ҫɾ��ͼ���λ��--------------"<<endl;
            int k;
            cin>>k;
            if(k>test.bks.size())
            {
                cout<<"------����ʧ�ܣ�δ�ҵ���ͼ�飡------"<<endl;
                continue;
            }
            test.shan(k-1);
            test.print();
        }
        else if(z==5)
            cout<<"-------����"<<test.bks.size()<<"��ͼ��-------"<<endl;
        else if(z==6)
        {
            vector<Book> t;
            for(int i=0;i<test.bks.size();i++)
                for(int j=0;j<test.bks.size();j++)
                    if(i!=j&&test.bks[i]==test.bks[j])
                    {
                        test.shan(j);
                        j--;
                    }
            test.print();
        }
        else if(z==7)
        {
            cout<<"------------�����ͼ�������------------"<<endl;
            string s;
            cin>>s;
            bool b=0;
            cout<<"���ͼ�飺";
            for(int i=0;i<test.bks.size();i++)
                if(test.bks[i].name==s)
                {
                    b=1;
                    test.xprint(i);
                }
            if(!b) cout<<"----------û�����----------"<<endl;
        }
        else if(z==8)
        {
            double ave=0;
            for(int i=0;i<test.bks.size();i++)
                ave+=test.bks[i].price;
            ave/=test.bks.size();
            for(int i=0;i<test.bks.size();i++)
                test.bks[i].price=test.bks[i].price>ave?test.bks[i].price*1.1:test.bks[i].price*1.2;
            test.print();
        }
        else if(z==9)
        {
            sort(test.bks.begin(),test.bks.end(),cmp);
            test.print();
        }
        else if(z==-1)
        {
            double ax=0;
            for(int i=0;i<test.bks.size();i++)
                ax=max(ax,test.bks[i].price);///
            int s=0;
            for(int i=0;i<test.bks.size();i++)
                if(ax==test.bks[i].price)
                    s++;
            cout<<"---------��"<<s<<"�����ͼ��--------"<<endl;
            for(int i=0;i<test.bks.size();i++)
                if(ax==test.bks[i].price)
                test.xprint(i);
        }
        else if(z==-2)
        {
        	cout<<"-----�û��ֲ�-----"<<endl;
			cout<<"��ϵͳ֧���û�������Ա����һЩ�򵥵��鼮������"<<endl;
			cout<<"��ϵͳ֧���û����������鼮��Ŀ¼���ڷ�λ�á���Ŀ�Ȳ�����"<<endl;
			cout<<"���Ը���ϵͳָ�����С�"<<endl; 
		}
    }
    return 0;
}

