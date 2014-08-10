//
//  CCShapeDrawNode.h
//  HelloCpp
//
//  Created by zhang zhiyu on 14-8-10.
//
//

#ifndef __York__CCShapeDrawNode__
#define __York__CCShapeDrawNode__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class CCShapeDrawNode : public CCDrawNode
{
public:
    CCShapeDrawNode();
    virtual ~CCShapeDrawNode();
    static CCShapeDrawNode* create();
    virtual bool init();

    /** 该函数用于画一个椭圆，椭圆的中心是限定矩形的中心
     * @param   leftTop     限定矩形左上角的坐标
     * @param   rightBottom 限定矩形右下角的坐标
     *
     * PS:当矩形是一个正方形时，得到的是一个圆形
     *
     */
    void drawEllipse(const CCPoint &leftTop, const CCPoint &rightBottom, float thick, const ccColor4F &color);
    
    /** 该函数画一个带圆角的矩形
     * @param   leftTop     矩形左上角的坐标
     * @param   rightBottom 矩形右下角的坐标
     *
     *
     */
    void drawRoundRect(const CCPoint &leftTop, const CCPoint &rightBottom, float thick, const ccColor4F &color);

};

#endif /* defined(__York__CCShapeDrawNode__) */
