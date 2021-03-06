/****************************************************************************
 Copyright (c) 2010-2011 cocos2d-x.org
 Copyright (c) 2010      Ray Wenderlich
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameOverScene.h"
#include "ComponentsTestScene.h"
#include "../ExtensionsTest.h"

using namespace cocos2d;

bool GameOverScene::init()
{
	if( TestCase::init() )
	{
		this->_layer = GameOverLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

GameOverScene::~GameOverScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = nullptr;
	}
}


bool GameOverLayer::init()
{
	if ( LayerColor::initWithColor( Color4B(255,255,255,255) ) )
	{
		auto winSize = Director::getInstance()->getWinSize();
		this->_label = Label::createWithTTF("","fonts/arial.ttf", 32);
		_label->retain();
		_label->setColor( Color3B(0, 0, 0) );
		_label->setPosition(winSize.width/2, winSize.height/2);
		this->addChild(_label);
		
		this->runAction( Sequence::create(
                                DelayTime::create(3),
                                CallFunc::create(CC_CALLBACK_0(GameOverLayer::gameOverDone, this)),
                                nullptr));
        
		return true;
	}
	else
	{
		return false;
	}
}

void GameOverLayer::gameOverDone()
{
    auto director = Director::getInstance();
    auto newScene = CocoStudioComponentsTest::create();
    director->replaceScene(newScene);
}

GameOverLayer::~GameOverLayer()
{
	if (_label)
	{
		_label->release();
		_label = nullptr;
	}
}
