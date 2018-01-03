/* cx16-il.h */
#ifndef IL_H
#define IL_H

INTERFACE(ILight)
{
    void (*init)(void*);
    void (*AddCell)(void*, void*);
    int (*Power)(void*);
};
#endif