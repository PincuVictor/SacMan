#pragma once
#include "Banker.hpp"
#include "Smungu.hpp"
#include "Sbungu.hpp"
#include "Sparga.hpp"
#include "Smarga.hpp"
#include "Map.hpp"

class BankerManager
{
    Banker* ig_Smungu = new Smungu;
    public:
    void CallUpdate(Map &map)
    {
        ig_Smungu = dynamic_cast<Smungu*>(ig_Smungu);
        ig_Smungu->Update(map);
    }
    void CallSetPosition(const int x, const int y)
    {
        ig_Smungu = dynamic_cast<Smungu*>(ig_Smungu);
        ig_Smungu->SetPosition(x, y);
    }
    [[nodiscard]] Banker* GetBanker(const char c) const
    {
        if(c == 1)
            return ig_Smungu;
        return ig_Smungu;
    }

    friend std::ostream& operator<<(std::ostream& stream, const BankerManager& B)
    {
        stream << B.ig_Smungu;
        return stream;
    }
};
