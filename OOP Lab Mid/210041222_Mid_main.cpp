#include <iostream>
#include <map>
#include <string>

using namespace std;

class CakeRecipe
{
private:
    string cake_name;
public:
    map<double, string> gram_measure, mL_measure;
    CakeRecipe();//zero-argumented constructor
    CakeRecipe(string name);//One argumented constructor for cake_name
    ~CakeRecipe();//Default destructor
    void addIngredients(string name, double measure, int isGram)
    {
        if (isGram)
        {
            gram_measure[measure] = name;
        }
        else
        {
            mL_measure[measure] = name;
        }
    }
    // const member function for display
    void display(CakeRecipe &c)const{ //reference object as parameter 
        cout<<"Cake Name: "<<c.cake_name<<endl<<"Solid Ingredients->"<<endl;
        for(auto e:c.gram_measure){
            cout<<"Ingredients: "<<e.second<<", Amount: "<<e.first<<"gm"<<endl;
        }
        cout<<"Liquid Ingredients->"<<endl;
        for(auto e:c.mL_measure){
            cout<<"Ingredients: "<<e.second<<", Amount: "<<e.first<<"mL"<<endl;
        }
    }
};
CakeRecipe::CakeRecipe()
{
    cake_name = "";
}
CakeRecipe::CakeRecipe(string name)
{
    cake_name = name;
}
CakeRecipe::~CakeRecipe()
{
    cake_name = "";
}

class ImperialConverter{
    map<double, string> ounce_measure;
    public:
        ImperialConverter(){}
        ImperialConverter(CakeRecipe &r){
            for(auto c:r.gram_measure){
                ounce_measure[(c.first*0.5)]=(c.second);
            }
            for(auto c:r.mL_measure){
                ounce_measure[(c.first*2.0)]=(c.second);
            }
        }
        ~ImperialConverter(){
            ounce_measure.clear();
        }
        //Automatic in-line function
        void display_ImpConversion() const{
            cout<<"Imperial Conversion:"<<endl;
            for(auto c:ounce_measure){
                cout<<"Ingredients: "<<c.second<<", Amount: "<<c.first<<" ounce"<<endl;
            }
        }
};

int main()
{
    CakeRecipe recipe1("Vanilla"), recipe2("Chocolate");
    const CakeRecipe dis;
    recipe1.addIngredients("Flour", 10, 1);
    recipe1.addIngredients("Sugar", 2, 1);
    recipe1.addIngredients("Salt", 1, 1);
    recipe1.addIngredients("Oil", 5, 0);
    recipe1.addIngredients("Water", 15, 0);
    dis.display(recipe1);

    const ImperialConverter convrt(recipe1);
    convrt.display_ImpConversion();
    // const ImperialConverter c2(recipe2);
    // c2.display_ImpConversion();
    return 0;
}
