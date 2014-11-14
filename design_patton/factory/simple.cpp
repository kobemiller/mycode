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
class Factory
{
public:
    soapBase *createSoap(PRODUCTTYPE type)
    {
        switch ( type )
        {
            case SFJ:
                return new SFJSoap();
                break;
            case XSL:
                return new XSLSoap();
                break;
            case NAS:
                return new NASSoap();
                break;
            default:
                break;
        }
    }
};

int main()
{
    Factory factory;
    
    soapBase *pSoap1 = factory.createSoap(SFJ);
    soapBase *pSoap2 = factory.createSoap(XSL);
    soapBase *pSoap3 = factory.createSoap(NAS);
    
    pSoap1->show();
    pSoap2->show();
    pSoap3->show();

    delete pSoap1;
    delete pSoap2;
    delete pSoap3;

    return 0;
}
