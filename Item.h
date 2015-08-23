#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item
{
    public:
        Item(std::string name);
        virtual ~Item();
        std::string GetName() { return m_Name; }
        void SetName(std::string val) { m_Name = val; }
    protected:
    private:
        std::string m_Name;
};

#endif // ITEM_H
