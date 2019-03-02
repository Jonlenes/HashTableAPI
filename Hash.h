#ifndef HASH_H
#define HASH_H


class Hash
{
public:
    Hash();
    virtual ~Hash();
    virtual long long hash() = 0;
};

#endif // HASH_H
