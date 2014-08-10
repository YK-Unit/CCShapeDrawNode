//
//  CCShapeDrawNode.cpp
//  HelloCpp
//
//  Created by zhang zhiyu on 14-8-10.
//
//

#include "CCShapeDrawNode.h"

CCShapeDrawNode::CCShapeDrawNode()
{
    
}

CCShapeDrawNode::~CCShapeDrawNode()
{
    
}

CCShapeDrawNode* CCShapeDrawNode::create()
{
    CCShapeDrawNode* pRet = new CCShapeDrawNode();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}


bool CCShapeDrawNode::init()
{
    if (!CCDrawNode::init()) {
        return false;
    }
    return true;
}

//思路参考自：http://discuss.cocos2d-x.org/t/draw-ellipse-ccdrawingprimitives/2405
void CCShapeDrawNode::drawEllipse(const cocos2d::CCPoint &leftTop, const cocos2d::CCPoint &rightBottom, float thick, const ccColor4F &color)
{
    float x_radius = fabs(rightBottom.x - leftTop.x)/2;
    float y_radius = fabs(rightBottom.y - leftTop.y)/2;
    float centerX = leftTop.x < rightBottom.x ? (leftTop.x + x_radius) : (rightBottom.x + x_radius);
    float centerY = leftTop.y < rightBottom.y ? (leftTop.y + y_radius) : (rightBottom.y + y_radius);
    
    int segs = 500;  //分段越多, 画的越细
    float a = M_PI;
    float dotRadius = thick;
    const float coef = 2.0f * (float)M_PI / segs;
    float radius, distance, angle, pointX, pointY;
    for(int i = 0; i <= segs; ++i)
    {
        radius = i * coef;
        distance = sqrt(pow(sinf(radius) * x_radius, 2) + pow(cosf(radius) * y_radius, 2));
        angle = atan2(sinf(radius) * x_radius, cosf(radius) * y_radius);
        pointX = distance * cosf(angle + a) + centerX;
        pointY = distance * sinf(angle + a) + centerY;
        
        this->drawDot(ccp(pointX, pointY), dotRadius, color);
    }
}

void CCShapeDrawNode::drawRoundRect(const cocos2d::CCPoint &leftTop, const cocos2d::CCPoint &rightBottom, float thick, const ccColor4F &color)
{
    //画圆角
    int segs = 500;  //分段越多, 画的越细
    float a = M_PI;
    float dotRadius = thick;
    const float coef = 2.0f * (float)M_PI / segs;
    float radius, distance, angle, pointX, pointY;
    
    float x_radius = fabs(rightBottom.x - leftTop.x)/4;
    float y_radius = fabs(rightBottom.y - leftTop.y)/4;
    float corner_radius = x_radius >= y_radius ? y_radius : x_radius;
    
    //画左上圆角
    //lt = left top corner
    float lt_centerX = leftTop.x < rightBottom.x ? (leftTop.x + corner_radius) : (rightBottom.x + corner_radius);
    float lt_centerY = leftTop.y < rightBottom.y ? (rightBottom.y - corner_radius) : (leftTop.y - corner_radius);
    for(int i = 0; i <= segs; ++i)
    {
        radius = i * coef;
        distance = sqrt(pow(sinf(radius) * corner_radius, 2) + pow(cosf(radius) * corner_radius, 2));
        angle = atan2(sinf(radius) * corner_radius, cosf(radius) * corner_radius);
        pointX = distance * cosf(angle + a) + lt_centerX;
        pointY = distance * sinf(angle + a) + lt_centerY;
        
        if (pointX <= lt_centerX && pointY >= lt_centerY) {
            this->drawDot(ccp(pointX, pointY), dotRadius, color);
        }
    }
    
    //画右上圆角
    //rt = right top corner
    float rt_centerX = leftTop.x < rightBottom.x ? (rightBottom.x - corner_radius) : (leftTop.x - corner_radius);
    float rt_centerY = leftTop.y < rightBottom.y ? (rightBottom.y - corner_radius) : (leftTop.y - corner_radius);
    for(int i = 0; i <= segs; ++i)
    {
        radius = i * coef;
        distance = sqrt(pow(sinf(radius) * corner_radius, 2) + pow(cosf(radius) * corner_radius, 2));
        angle = atan2(sinf(radius) * corner_radius, cosf(radius) * corner_radius);
        pointX = distance * cosf(angle + a) + rt_centerX;
        pointY = distance * sinf(angle + a) + rt_centerY;
        
        if (pointX >= rt_centerX && pointY >= rt_centerY) {
            this->drawDot(ccp(pointX, pointY), dotRadius, color);
        }
    }
    
    //画左下圆角
    //lb = left bottom corner
    float lb_centerX = leftTop.x < rightBottom.x ? (leftTop.x + corner_radius) : (rightBottom.x + corner_radius);
    float lb_centerY = leftTop.y < rightBottom.y ? (leftTop.y + corner_radius) : (rightBottom.y + corner_radius);
    for(int i = 0; i <= segs; ++i)
    {
        radius = i * coef;
        distance = sqrt(pow(sinf(radius) * corner_radius, 2) + pow(cosf(radius) * corner_radius, 2));
        angle = atan2(sinf(radius) * corner_radius, cosf(radius) * corner_radius);
        pointX = distance * cosf(angle + a) + lb_centerX;
        pointY = distance * sinf(angle + a) + lb_centerY;
        
        if (pointX <= lb_centerX && pointY <= lb_centerY) {
            this->drawDot(ccp(pointX, pointY), dotRadius, color);
        }
    }
    
    //画右下圆角
    //rb = right bottom corner
    float rb_centerX = leftTop.x < rightBottom.x ? (rightBottom.x - corner_radius) : (leftTop.x - corner_radius);
    float rb_centerY = leftTop.y < rightBottom.y ? (leftTop.y + corner_radius) : (rightBottom.y + corner_radius);
    for(int i = 0; i <= segs; ++i)
    {
        radius = i * coef;
        distance = sqrt(pow(sinf(radius) * corner_radius, 2) + pow(cosf(radius) * corner_radius, 2));
        angle = atan2(sinf(radius) * corner_radius, cosf(radius) * corner_radius);
        pointX = distance * cosf(angle + a) + rb_centerX;
        pointY = distance * sinf(angle + a) + rb_centerY;
        
        if (pointX >= rb_centerX && pointY <= rb_centerY) {
            this->drawDot(ccp(pointX, pointY), dotRadius, color);
        }
    }
    
    
    
    //画线段
    float largeX = leftTop.x < rightBottom.x ? rightBottom.x : leftTop.x;
    float littleX = leftTop.x < rightBottom.x ? leftTop.x : rightBottom.x;
    float largeY = leftTop.y < rightBottom.y ? rightBottom.y : leftTop.y;
    float lillteY = leftTop.y < rightBottom.y ? leftTop.y : rightBottom.y;
    
    //画左竖线
    //lv = left vertical line
    CCPoint lv_from = ccp(littleX,largeY - corner_radius);
    CCPoint lv_to = ccp(littleX,lillteY + corner_radius);
    this->drawSegment(lv_from, lv_to, thick, color);
    //画右竖线
    //rv = right vertical line
    CCPoint rv_from = ccp(largeX,largeY - corner_radius);
    CCPoint rv_to = ccp(largeX,lillteY + corner_radius);
    this->drawSegment(rv_from, rv_to, thick, color);
    //画上横线
    //th = top horizontal line
    CCPoint th_from = ccp(littleX + corner_radius,largeY);
    CCPoint th_to = ccp(largeX - corner_radius,largeY);
    this->drawSegment(th_from, th_to, thick, color);
    //画下横线
    //bh = bottom horizontal line
    CCPoint bh_from = ccp(littleX + corner_radius,lillteY);
    CCPoint bh_to = ccp(largeX - corner_radius,lillteY);
    this->drawSegment(bh_from, bh_to, thick, color);
    
}

