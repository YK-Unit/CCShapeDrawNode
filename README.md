CCShapeDrawNode
===============

CCShapeDrawNode is a CCDrawNode subclass, it provides the functions to draw Ellipse and RoundRect.

---
##Usage#
```C++
    CCShapeDrawNode* shapeNode = CCShapeDrawNode::create();
    //draw ellipse
    shapeNode->drawEllipse(ccp(100,250), ccp(150, 200), 2, ccc4f(0, 1, 0, 1));
    //draw roundrect
    shapeNode->drawRoundRect(ccp(200,300), ccp(250, 200), 2, ccc4f(0, 0, 1, 1));
    this->addChild(shapeNode);

```