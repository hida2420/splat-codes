#pragma once

#include "internal/library_functions.hpp"
#include "internal/enumerations.hpp"
#include "internal/internal_templates.hpp"
#include "internal/definitions.hpp"

__attribute__((noinline))
void aimBot()
{

    //標準の状態を読み込む
    unsigned int judge = readPointerInternal(playerBase, startingMemoryRanges, endingMemoryRanges, paramStandard, THIRTY_TWO_BIT);

    //標準が試し打ちの的に重なったら攻撃
    if(judge == 0)
    {
	    writePointerInternal(playerBase, startingMemoryRanges, endingMemoryRanges, paramAttack, 0x0FFFFFFF, THIRTY_TWO_BIT);
    }

    executeAssemblyReturn();
}

//ランダムさぶうえぽん　A押しながらボムなげる
void randomSubs()
{
    unsigned int key = readInternal(keyAddress, THIRTY_TWO_BIT);
    if(key == A)//while?
    {
        for(int i = 0; i < 3; i++)
        {
            writePointerInternal(playerBase, startingMemoryRanges, endingMemoryRanges, subID, i, THIRTY_TWO_BIT);
            if(i == 2)
            {
                i = 0;
            }
        }
    }    
}