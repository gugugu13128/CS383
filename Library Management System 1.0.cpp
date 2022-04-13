#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
struct Book{
    string no;   //8位书号
    string name; //书名
    double price;     //价格
    bool operator ==(const Book& a)
    {
        return a.name==this->name&&a.no==this->no&&a.price==this->price;
    }
};
bool cmp(Book &a,Book &b)
{
    return a.price>b.price;
}
class sstm//图书管理系统
{
public:
    vector<Book> bks;
    void print();//全部打印
    void xprint(int k);//打印某一项
    void add(int k,Book t);
    void shan(int k);
};
void sstm::xprint(int k)
{
    if(k>=bks.size()||k<0)
        cout<<"-----------没有这本书-----------";
    else
        cout<<"---书名："<<bks[k].name<<"---书号："<<bks[k].no<<"---价格："<<fixed<<setprecision(2)<<bks[k].price<<"---"<<endl;
}
void sstm::print()
{
    for(int i=0;i<bks.size();i++) xprint(i);
}
void sstm::add(int k,Book t)
{
    bks.insert(bks.begin()+k,t);//在k处插入T 
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
        cout<<"输入1-----------------------输入图书信息"<<endl;
        cout<<"输入2-----------逐个显示图书表中所有图书"<<endl;
        cout<<"输入3---将新图书插入到图书表中指定的位置"<<endl;
        cout<<"输入4---------------------------删除图书"<<endl;
        cout<<"输入5-----------------------统计图书数量"<<endl;
        cout<<"输入6-------------------------------去重"<<endl;
        cout<<"输入7---------------------查找最爱的图书"<<endl;
        cout<<"输入8---------------------------批量修改"<<endl;
        cout<<"输入9-----------------将图书按照降序排列"<<endl;
        cout<<"输入-1----------------------查找最贵图书"<<endl;
        cout<<"输入-2--------------------------用户手册"<<endl; 
        cout<<"输入0-------------------------------退出"<<endl;
        cin>>z;
        if(z==1)
        {
            double c;
            cout<<"依次输入书号书名价格添加图书，输入0 0 0时结束添加"<<endl;
            string a,b;
            cin>>a>>b>>c;
            while(a!="0"&&b!="0"&&c!=0)
            {
                Book tmp;
                tmp.name=b;
                tmp.no=a;
                tmp.price=c;
                test.bks.push_back(tmp);//末尾插入 
                cin>>a>>b>>c;
            }
        }
        else if(z==2)
        {
            cout<<"-------------------------共有"<<test.bks.size()<<"本图书---------------------"<<endl;
            test.print();
        }
        else if(z==3)
        {
            int k;
            double c;
            string a,b;
            cout<<"-------依次输入插入位置、书号、书名、价格-------"<<endl;
            cin>>k>>a>>b>>c;
            if(k>test.bks.size())
            {
                cout<<"---------抱歉，入库位置非法！-------"<<endl;
                continue;
            }
            Book tmp;
            tmp.name=b;
            tmp.no=a;
            tmp.price=c;
            test.add(k-1,tmp);//k-1处插入tmp 
            test.print();
        }
        else if(z==4)
        {
            cout<<"--------------输入要删除图书的位置--------------"<<endl;
            int k;
            cin>>k;
            if(k>test.bks.size())
            {
                cout<<"------出库失败，未找到该图书！------"<<endl;
                continue;
            }
            test.shan(k-1);
            test.print();
        }
        else if(z==5)
            cout<<"-------共有"<<test.bks.size()<<"本图书-------"<<endl;
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
            cout<<"------------输入最爱图书的书名------------"<<endl;
            string s;
            cin>>s;
            bool b=0;
            cout<<"最爱的图书：";
            for(int i=0;i<test.bks.size();i++)
                if(test.bks[i].name==s)
                {
                    b=1;
                    test.xprint(i);
                }
            if(!b) cout<<"----------没有最爱！----------"<<endl;
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
            cout<<"---------有"<<s<<"本最贵图书--------"<<endl;
            for(int i=0;i<test.bks.size();i++)
                if(ax==test.bks[i].price)
                test.xprint(i);
        }
        else if(z==-2)
        {
        	cout<<"-----用户手册-----"<<endl;
			cout<<"该系统支持用户及管理员进行一些简单的书籍管理活动："<<endl;
			cout<<"该系统支持用户查阅所有书籍的目录、摆放位置、数目等操作。"<<endl;
			cout<<"可以根据系统指引进行。"<<endl; 
		}
    }
    return 0;
}

