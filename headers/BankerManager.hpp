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
    Banker* ig_Sbungu = new Sbungu;
    public:
    void CallUpdate(Map &map, SacMan &ig_SacMan)
    {
        ig_Smungu = dynamic_cast<Smungu*>(ig_Smungu);
        ig_Smungu->Update(map, ig_SacMan);
        ig_Sbungu = dynamic_cast<Sbungu*>(ig_Sbungu);
        ig_Sbungu->Update(map, ig_SacMan);
    }
    void CallSetPosition(const int x, const int y)
    {
        ig_Smungu = dynamic_cast<Smungu*>(ig_Smungu);
        ig_Smungu->SetPosition(x, y);
        ig_Sbungu = dynamic_cast<Sbungu*>(ig_Sbungu);
        ig_Sbungu->SetPosition(x, y);
    }
    [[nodiscard]] Banker* GetBanker(const char c) const
    {
        if(c == 1)
            return ig_Smungu;
        if(c == 2)
            return ig_Sbungu;
        return ig_Smungu;
    }

    friend std::ostream& operator<<(std::ostream& stream, const BankerManager& B)
    {
        stream << B.ig_Smungu;
        stream << B.ig_Sbungu;
        return stream;
    }
};
