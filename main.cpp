#include <iostream>
#include <string>

int main(){
    std::string num1="",num2="",lar="",sum="",sub="";
    std::cout<<"First number  >> ";
    std::cin>>num1;
    std::cout<<"Second number >> ";
    std::cin>>num2;
    int min=0,dis=0,plus=0,minus=0,len=1,bigger=0;

    if((num1.length() < num2.length()) || (num1.length()==num2.length() && (int)num1[0]<(int)num2[0])){
        min=num1.length();
        dis=num2.length()-min;
        lar=num2.substr(0,dis);
        num2.erase(0,dis);
        bigger++;
    }
    else{
        min=num2.length();
        dis=num1.length()-min;
        lar=num1.substr(0,dis);
        num1.erase(0,dis);
    }
    
    for (int i = min-1; i >= 0; i--,len++) {
        sum.insert(0,std::to_string((num1[i]-'0')+(num2[i]-'0')+plus));
        if((i!=0 || lar.length()!=0) && sum.length()>len){
            plus=1;
            sum.erase(0,1);
        }
        else
            plus=0;
        
        if(bigger)
            dis=(num2[i]-'0')-(num1[i]-'0')+minus;
        
        else
            dis=(num1[i]-'0')-(num2[i]-'0')+minus;

        if(dis<0){
            sub.insert(0,std::to_string(10+dis));
            minus=-1;
        }
        else{
            sub.insert(0,std::to_string(dis));
            minus=0;
        }
    }

    for (int i = lar.length()-1; i >= 0; i--,len++) {
        sum.insert(0,std::to_string((lar[i]-'0')+plus));
        if(i!=0 && sum.length()>len){
            plus=1;
            sum.erase(0,1);
        }
        else
            plus=0;
        
        dis=(lar[i]-'0')+minus;

        if(dis<0){
            sub.insert(0,std::to_string(10+dis));
            minus=-1;
        }
        else{
            sub.insert(0,std::to_string(dis));
            minus=0;
        }
    }
    for(int i=0; sub.length()>1;){
        if(sub[i]=='0')
            sub.erase(0,1);
        else 
            break;
    }
    if(bigger)
        sub.insert(0,"-");

    std::cout<<"Sum           >> "<<sum<<std::endl;
    std::cout<<"Sub           >> "<<sub<<std::endl;
    
    return 0;
}