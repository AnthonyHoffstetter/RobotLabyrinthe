#ifndef ALGORITHMEMAINDROITE_H
#define ALGORITHMEMAINDROITE_H
#include "algorithme.h"


class algorithmeMainDroite : public algorithme
{
    public:
        void executer(const robot &r, const terrain &t) override;
};

#endif // ALGORITHMEMAINDROITE_H
