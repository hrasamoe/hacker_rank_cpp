#include<bits/stdc++.h>
using namespace std;

class Box{
    private: 
        int l, b, h;
    public:
        Box(int length = 0, int breadth = 0, int height = 0)
        {
            l = length;
            b = breadth;
            h = height;
        }

        Box(const Box& B)
        {
            l = B.l;
            b = B.b;
            h = B.h;
        }

        int getLength() const
        {
            return l;
        }
        int getBreadth() const
        {
            return b;
        }
        int getHeight() const
        {
            return h;
        }

        long long CalculateVolume() const
        {
            return (long long)l * b * h;
        }

        bool operator<(const Box& other) const
        {
            if (l < other.l) 
                return true;
            if ((b < other.b) && (l == other.l)) 
                return true;
            if ((h < other.h) && (b == other.b) && (l == other.l)) 
                return true;
            
            return false;
        }
};

ostream& operator<<(ostream& os, const Box& p)
{
    os << p.getLength() << " " << p.getBreadth() << " " << p.getHeight();
    return os;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}