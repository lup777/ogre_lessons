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
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0, 0, 0));

  Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
  ninjaEntity->setCastShadows(true);

  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

  Ogre::MeshManager::getSingleton().createPlane(
						"ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane,
						1500, 1500, 20, 20,
						true,
						1, 5, 5,
						Ogre::Vector3::UNIT_Z);

  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

  groundEntity->setCastShadows(false);
  groundEntity->setMaterialName("Examples/Rockwall");

  mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

  Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
  spotLight->setDiffuseColour(0, 0, 1.0);
  spotLight->setSpecularColour(0, 0, 1.0);
  spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
  spotLight->setDirection(-1, -1, 0);
  spotLight->setPosition(Ogre::Vector3(200, 200, 0));
  spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

  Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
  directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);

  directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
  directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));

  directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

  Ogre::Light* pointLight = mSceneMgr->createLight("pointLight");
  pointLight->setType(Ogre::Light::LT_POINT);

  pointLight->setDiffuseColour(.3, .3, .3);
  pointLight->setSpecularColour(.3, .3, .3);

  pointLight->setPosition(Ogre::Vector3(0, 150, 250));
}

void TutorialApplication::createCamera()
{
  mCamera = mSceneMgr->createCamera("PlayerCam");
  mCamera->setPosition(Ogre::Vector3(0, 300, 500));
  mCamera->lookAt(Ogre::Vector3(0, 0, 0));
  mCamera->setNearClipDistance(5);
  mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void TutorialApplication::createViewports()
{
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
  vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

  mCamera->setAspectRatio(
			  Ogre::Real(vp->getActualWidth()) /
			  Ogre::Real(vp->getActualHeight()));
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
