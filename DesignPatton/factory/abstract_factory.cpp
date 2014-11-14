#include <iostream>
enum PRODUCTTYPE { SFJ, XSL, NAS };
enum TOOTHTYPE { HR, ZH };

class SoapBase
{
public:
    virtual ~SoapBase() {};
    virtual void show() = 0;
};
class SFJSoap : public SoapBase
{
public:
    void show() { std::cout << "SFJ soap!" << std::endl; }
};
class XSLSoap : public SoapBase
{
public:
    void show() { std::cout << "XSL soap!" << std::endl; }
};
class NASSoap : public SoapBase
{
public:
    void show() { std::cout << "NAS soap!" << std::endl; }
};

class ToothBase
{
public:
    virtual ~ToothBase() {};
    virtual void show() = 0;
};
class HRTooth : public ToothBase
{
public:
    void show() { std::cout << "hei ren Toothpaste" << std::endl; }
};
class ChinaTooth : public ToothBase
{
public:
    void show() { std::cout << "china Toothpaste" << std::endl; }
};

class FactoryBase
{
public:
    virtual SoapBase * createSoap() = 0;
    virtual ToothBase * createToothpaste() = 0;
};
class FactoryA
{
public:
    SoapBase * createSoap() { return new SFJSoap(); }
    ToothBase * createToothpaste() { return new HRTooth(); }
};
class FactoryB
{
public:
    SoapBase * createSoap() { return new NASSoap(); }
    ToothBase * createToothpaste() { return new ChinaTooth(); }
};

int main()
{
    FactoryA factory1;
    FactoryB factory2;

    SoapBase *pSoap1 = NULL;
    ToothBase *pToothpaste1 = NULL;
    pSoap1 = factory1.createSoap();
    pToothpaste1 = factory1.createToothpaste();
    pSoap1->show();
    pToothpaste1->show();

    SoapBase *pSoap2 = NULL;
    ToothBase *pToothpaste2 = NULL;
    pSoap2 = factory2.createSoap();
    pToothpaste2 = factory2.createToothpaste();
    pSoap2->show();
    pToothpaste2->show();
    
    return 0;
}
