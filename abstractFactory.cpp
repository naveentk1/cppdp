/*client: testing client code with the fist factory type:
the product of B1
The result of the B1's collab with (The result of Product A1)

client: testing the same client with the second factory type:
the product of B2
The result of the B1's collab with (The result of Product A2)*/

#include <bits/stdc++.h>

class AbstractProductA 
{
    public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionA() const = 0;    
};

class ConcreteProductA1 : public AbstractProductA
{
    public:
    std::string UsefulFunctionA() const override
    {
        return "The result of Product A1";
    }
};

class ConcreteProductA2 : public AbstractProductA
{
    std::string UsefulFunctionA() const override
    {
        return "The result of Product A2";
    }
};
//--------------------------------------------------

class AbstractProductB
{
    public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
  public: 
  std::string UsefulFunctionB () const override
  {
    return "the product of B1";
  }
  std::string AnotherUsefulFunctionB(const AbstractProductA  &collaborator) const override 
  {
   const std::string result = collaborator.UsefulFunctionA();
   return "The result of the B1's collab with ("+ result +")";   
  }  
};


class ConcreteProductB2 : public AbstractProductB
{
  public: 
  std::string UsefulFunctionB () const override 
  {
    return "the product of B2";
  } 
  
  std::string AnotherUsefulFunctionB(const AbstractProductA  &collaborator) const override 
  {
   const std::string result = collaborator.UsefulFunctionA();
   return "The result of the B1's collab with ("+ result +")"; 
  } 
};

//----------------------------------------------------------------------------------------

class AbstractFactory
{
    public:
    virtual ~AbstractFactory(){};
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
    public:
    AbstractProductA *CreateProductA() const override 
    {
        return new ConcreteProductA1();
    }

    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
   public:
    AbstractProductA *CreateProductA() const override 
    {
        return new  ConcreteProductA2;
    }
    
    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB2();
    }

};

void Clientcode(const AbstractFactory &factory)
{
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();

    std::cout << product_b -> UsefulFunctionB() << "\n";
    std::cout << product_b -> AnotherUsefulFunctionB(*product_a) << "\n";
    
    delete product_a; delete product_b;

}

int main()
{
    std::cout << "client: testing client code with the fist factory type:\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    Clientcode(*f1);
    delete f1;
    std::cout << std::endl;

    std::cout<<"client: testing the same client with the second factory type:\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    Clientcode(*f2);
    delete f2;

    return 0;

}