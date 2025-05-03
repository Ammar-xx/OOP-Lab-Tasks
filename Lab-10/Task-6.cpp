#include <iostream>
#include <fstream>

using namespace std;

class InventoryItem{
    public:
        int itemID;
        char itemName[20];
    InventoryItem(int id,char item[],int size)
    {
        itemID=id;
        for(int i=0;i<size;i++)
        {
            itemName[i]=item[i];
        }
    }
};

int main()
{
    char item[]="Salt";
    InventoryItem it(1,item,sizeof(item));
    ofstream binar("inventory.dat",ios::binary);
    if(!binar)
    {
        cout<<"Error opening file\n";
        return 1;
    }
    int id=1;
    binar.write(reinterpret_cast<char*>(&it.itemID), sizeof(id));
    binar.write(it.itemName,sizeof(it.itemName));

    binar.close();

    ifstream out("inventory.dat",ios::binary);
    int i;
    char arr[20];
    out.read(reinterpret_cast<char*>(&i), sizeof(i));
    out.read(arr,sizeof(arr));

    out.close();

    cout<<"Item ID: "<<i<<endl;
    cout<<"Item Name: ";
    for(int j=0;j<sizeof(arr);j++)
    {
        if(arr[j]=='\0')
        {
            break;
        }
        cout<<arr[j];
    }
}