#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

namespace Art_Space
{
class phoneBook
{
char name[20],phno[11];
public:
void getdata();
void showdata();
char *getname(){ return name; }
char *getphno(){ return phno; }
void update(char *nm,char *telno)
{
    strcpy(name,nm);
    strcpy(phno,telno);
}
    void newrecord();
    void display();
    void display(char *nm);
    void searchpname();
    void updatetelno();
    void deleterec();

};

void phoneBook :: getdata()
{
    std::cout << "\nEnter Name : ";
    std::cin >> name;
    repeat:
    std::cout << "Enter Phone No. : ";
    std::cin >> phno;            //CAN CREATE A FUNCTION THAT CHECKS WHETHER STRING IS DIGIT OR NOT

    for(int i=0;i<strlen(phno);i++)
      {
           try
           {
                if(phno[i]<48 || phno[i]>57||strlen(phno)!=9)
                throw phno[i];
           }
           catch(char a)
           {
               std::cout << "Enter a valid number" << std::endl;
               std::cout << "Try again" << std::endl;
               goto repeat;
           }
      }
   
}

void phoneBook :: showdata(){
    std::cout << "\n";
    std::cout << std::setw(20) << name;
    std::cout << std::setw(15) << phno;
}

void phoneBook :: newrecord()
{
    int found=0;
    char rrep[11];
    char nmopi[20];
    getdata();
    strcpy(nmopi,name);
    strcpy(rrep,phno);
    std::fstream file;
    file.open("phone.txt", std::ios::in | std::ios::app | std::ios::binary );
    while(file.read((char *) this, sizeof(*this)))
        {
            if(strcmp(rrep,getphno())==0)
            {
                found=1;
                break;
            }
        }
    file.clear();
    file.close();
    if(found==1)
            {
                std::cout<<"\n\n---Contact already exist---\n";
            }
     else
            {
                file.open("phone.txt", std::ios::app | std::ios::binary );
                update(nmopi,rrep);
                file.write((char *) this, sizeof(*this));
                std::cout<<"Record Added Succesfully\n";
                file.close();
            }
    

}
void phoneBook :: display()
{
   //Display All Records
    std::fstream file;
    file.open("phone.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::binary );
    file.seekg(0,std::ios::beg);
    std::cout<<"\n\nRecords in Phone Book\n";
    while(file)
    {
        file.read((char *) this, sizeof(*this));
        if(!file.eof())
            showdata();
    }
    file.clear();
    file.close();
}

void phoneBook :: display(char *nm)               //function overloading
{  //Search Tel. no. when person name is known.
    char c,telno[11];
    int cnt,found=0;

    std::fstream file;
    file.open("phone.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::binary );
    file.seekg(0,std::ios::beg);
    while(file.read((char *) this, sizeof(*this)))
    {   
        
        if(strcmp(nm,getname())==0)            
        {
            found=1;
            showdata();
        } 
    }
    file.clear();
    if(found==0)
    std::cout << "\n\n---Record Not found---\n";
    file.close();

}

void phoneBook :: searchpname()
{
          //Search name on basis of tel. no
    char c,ch,nm[20],telno[11];
    int cnt,found=0;
    std::cout << "\n\nEnter Telephone No : ";
    std::cin >> telno;
    std::fstream file;
    file.open("phone.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::binary );
    file.seekg(0,std::ios::beg);
    while(file.read((char *) this, sizeof(*this)))
    {
        if(strcmp(telno,getphno())==0)
        {
            found=1;
            showdata();
        }
    }
    file.clear();
    if(found==0)
        std::cout << "\n\n---Record Not found---\n";
    file.close();

}

 
    void phoneBook :: updatetelno()
     {   //Update Telephone No.
               int k;
                std::fstream file;
                file.open("phone.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::binary );
                std::cout << "Enter 1 to update name"<< std::endl;
                std::cout << "Enter 2 to update phone number" << std::endl;
                std::cin >> k;
                if(k==1)
                {
                   char c,ch,nm[20],newnm[15],teleno[15];
                   int cnt=0,found=0;
                   std::cout << "\n\nEnter Name : ";
                   std::cin >> nm;
                   file.seekg(0,std::ios::beg);
                   while(file.read((char *) this, sizeof(*this)))
                   {
                      cnt++;
                      if(strcmp(nm,getname())==0)
                      {
                          found=1;
                          break;
                      }
                   }
                   file.clear();
                   if(found==0)
                      std::cout << "\n\n---Record Not found---\n";
                   else
                   {  strcpy(teleno,phno);
                      int location = (cnt-1) * sizeof(*this);
                      std::cin.get(ch);
                      if(file.eof())
                          file.clear();
                      std::cout << "Enter New Name: ";
                      std::cin >> newnm;
                      file.seekp(location);
                      update(newnm,teleno);
                      file.write((char *) this, sizeof(*this));
                      file.flush();
                   }
                 }
               if(k==2)
               {
                 char c,ch,nm[20],telno[15],newteleno[15];
                 int cnt=0,found=0;
                 std::cout<<"\n\nEnter Phone number : ";
                 std::cin>>telno;
                 file.seekg(0,std::ios::beg);
                 while(file.read((char *) this, sizeof(*this)))
                 {
                    cnt++;
                    if(strcmp(telno,getphno())==0)
                    {
                        found=1;
                        break;
                    }
                 }
                 file.clear();
                 if(found==0)
                    std::cout<<"\n\n---Record Not found---\n";
                 else
                 {  strcpy(nm,name);
                    int location = (cnt-1) * sizeof(*this);
                    std::cin.get(ch);
                    if(file.eof())
                        file.clear();

                    std::cout<<"Enter New Phone number: ";
                    std::cin>>newteleno;
                    file.seekp(location);
                    update(nm,newteleno);
                    file.write((char *) this, sizeof(*this));
                    file.flush();
                 }
               }

                 file.close();
            }


void phoneBook :: deleterec()
{
    char bb[20],teleno[11];
    std::cout << "Enter the name of the record which is to be deleted:";
    std::cin >> bb;
    std::fstream file;
    file.open("phone.txt",  std::ios::in | std::ios::binary );
    std::fstream fout;
    fout.open("tempfile.txt",std::ios::out | std::ios::binary);
    int i=0,j=0,found=0;
    file.read((char *) this, sizeof(*this));
    while(!file.eof())
    {
        i++;
        if(strcmp(bb,getname()))
        {
            fout.write((char*)this,sizeof(*this));
            j++;
        }
        file.read((char*)this,sizeof(*this));
        

    }
    fout.close();
    file.close();
    if(i-j<=1)
    {
    
        file.close();
        remove("phone.txt");
        rename("tempfile.txt","phone.txt");
        if(j<i)
        std::cout << "RECORD DELETED"<< std::endl;
        
        
        if(j==i)
        std::cout << "RECORD NOT FOUND"<< std::endl;
        
    }
    else
    {
        std::cout << "\n\nTWO SAME CONTACT NAMES EXIST\n" << std::endl;    
        file.open("phone.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::binary );
        file.seekg(0,std::ios::beg);
    while(file.read((char *) this, sizeof(*this)))
    {
        if(strcmp(bb,getname())==0)
        {
            found=1;
            showdata();
            std::cout << std::endl;
        }
    }
        file.clear();
        file.close();
        std::cout << "\n\n NOW ENTER THE CONTACT NUMBER YOU WANT TO DELETE :  " << std::endl;
        std::cin>>teleno;
        file.open("phone.txt",  std::ios::in | std::ios::binary );
        fout.open("tempfileph.txt",std::ios::out | std::ios::binary);
        file.read((char *) this, sizeof(*this));
        i=0;
        j=0;
        while(!file.eof())
        {
            i++;
            if(strcmp(teleno,getphno()))
            {
                fout.write((char*)this,sizeof(*this));
                j++;
            }
            file.read((char*)this,sizeof(*this));
        }
        fout.close();
        file.close();
        remove("phone.txt");
        rename("tempfileph.txt","phone.txt");
        if(j<i)
            std::cout<<"\n\nRECORD DELETED\n\n" << std::endl;   
        else
            std::cout<<"RECORD NOT FOUND" << std::endl;
    }
 
   }
}


