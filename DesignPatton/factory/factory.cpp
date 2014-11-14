#include <iostream>
enum PRODUCTTYPE { SFJ, XSL, NAS };
class soapBase
{
public:
    virtual ~soapBase() {};
    virtual void show() = 0;
};
class SFJSoap : public soapBase
{
public:
    void show() { std::cout << "SFJ soap!" << std::endl; }
};
class XSLSoap : public soapBase
{
public:
    void show() { std::cout << "XSL soap!" << std::endl; }
};
class NASSoap : public soapBase
{
public:
    void show() { std::cout << "NAS soap!" << std::endl; }
};
class FactoryBase
{
public:
    virtual soapBase *createSoap() = 0;
};
class SFJFactory : public FactoryBase
{
public:
    soapBase *createSoap() { return new SFJSoap(); }
};
class XSLFactory : public FactoryBase
{
public:
    soapBase *createSoap() { return new XSLSoap(); }
};
class NASFactory : public FactoryBase
{
public:
    soapBase *createSoap() { return new NASSoap(); }
};
int main()
{
    SFJFactory factory1;
    XSLFactory factory2;
    NASFactory factory3;

    soapBase *pSoap1 = factory1.createSoap();
    soapBase *pSoap2 = factory2.createSoap();
    soapBase *pSoap3 = factory3.createSoap();
    
    pSoap1->show();
    pSoap2->show();
    pSoap3->show();

    delete pSoap1;
    delete pSoap2;
    delete pSoap3;

    return 0;
}
