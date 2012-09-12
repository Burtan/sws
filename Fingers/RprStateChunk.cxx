#include "stdafx.h"

#include "RprStateChunk.hxx"

RprStateChunk::RprStateChunk(const char *stateChunk)
{
    mChunk = stateChunk;
}

const char *RprStateChunk::get()
{
    return mChunk;
}

RprStateChunk::~RprStateChunk()
{
    FreeHeapPtr((void *)mChunk);
}
