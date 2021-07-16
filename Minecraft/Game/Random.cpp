#include "Random.h"
#include "../../WorldEdit/WorldEdit.h"

Minecraft::Random::Random()
{
    using random_constructor_t = __int64(__fastcall*)(Random*);
    random_constructor_t constructRandom = reinterpret_cast<random_constructor_t>(FindSignature(""));
}

int Minecraft::Random::nextInt(int)
{
    return 0;
}
