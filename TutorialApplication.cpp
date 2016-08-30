#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // create your scene here :)
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
  Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode->attachObject(ogreEntity);
  Ogre::Light* light = mSceneMgr->createLight("MainLight");
  light->setPosition(20, 80, 50);
  mCamera->setPosition(0, 47, 222);
}


#ifdef __cplusplus
extern "C" {
#endif

    int main(int argc, char *argv[])
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
