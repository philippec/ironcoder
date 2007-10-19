/*
 *     Generated by class-dump 3.1.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2006 by Steve Nygard.
 */

/*
 * File: /System/Library/Frameworks/ScreenSaver.framework/Versions/A/ScreenSaver
 * Arch: Intel 80x86 (i386)
 *       Current version: 1.0.0, Compatibility version: 1.0.0
 */
 
#import <Cocoa/Cocoa.h>

@protocol ScreenSaverControl
- (void)restartForUser:(id)fp8;
- (BOOL)screenSaverCanRun;
- (void)screenSaverDidFade;
- (void)screenSaverDidFadeInBackground:(BOOL)fp8 psnHi:(unsigned int)fp12 psnLow:(unsigned int)fp16;
- (BOOL)screenSaverIsRunning;
- (BOOL)screenSaverIsRunningInBackground;
- (void)screenSaverStartNow;
- (void)screenSaverStopNow;
- (double)screenSaverTimeRemaining;
- (void)setScreenSaverCanRun:(BOOL)fp8;
@end

@interface ScreenSaverApertureProject : NSObject
{
    NSString *_name;
    NSString *_path;
    BOOL _isMaster;
    NSArray *_photoDicts;
}

+ (id)_projectDataXMLPath;
+ (id)allProjects;
+ (id)projectNamed:(id)fp8;
+ (id)projectPathForName:(id)fp8 isMaster:(BOOL)fp12;
+ (BOOL)reloadAllProjects;
- (id)allImagePaths;
- (id)allPhotoDicts;
- (void)dealloc;
- (id)description;
- (id)imagesDirectory;
- (id)initWithName:(id)fp8 path:(id)fp12 photoDicts:(id)fp16 type:(BOOL)fp20;
- (BOOL)isLibrary;
- (id)name;

@end

@interface ScreenSaverController : NSObject <ScreenSaverControl>
{
    NSConnection *_connection;
    id _daemonProxy;
    void *_reserved;
}

+ (id)controller;
+ (id)daemonConnectionName;
+ (id)enginePath;
+ (id)monitor;
- (void)_connectionClosed:(id)fp8;
- (void)dealloc;
- (id)init;
- (void)restartForUser:(id)fp8;
- (BOOL)screenSaverCanRun;
- (void)screenSaverDidFade;
- (void)screenSaverDidFadeInBackground:(BOOL)fp8 psnHi:(unsigned int)fp12 psnLow:(unsigned int)fp16;
- (BOOL)screenSaverIsRunning;
- (BOOL)screenSaverIsRunningInBackground;
- (void)screenSaverStartNow;
- (void)screenSaverStopNow;
- (double)screenSaverTimeRemaining;
- (void)setScreenSaverCanRun:(BOOL)fp8;

@end

@interface ScreenSaverDefaults : NSUserDefaults
{
    void *_reserved4;
    void *_reserved5;
}

+ (id)defaultsForEngine;
+ (id)defaultsForModule:(id)fp8;
+ (id)defaultsForModuleWithName:(id)fp8;
+ (id)defaultsForUser:(id)fp8 moduleName:(id)fp12;
+ (void)resetStandardUserDefaults;
+ (id)standardUserDefaults;
- (void)dealloc;
- (id)dictionaryRepresentation;
- (id)initWithUser:(id)fp8 moduleName:(id)fp12;
- (id)objectForKey:(id)fp8;
- (id)persistentDomainForName:(id)fp8;
- (id)persistentDomainNames;
- (void)registerDefaults:(id)fp8;
- (BOOL)reload;
- (void)removeObjectForKey:(id)fp8;
- (void)removePersistentDomainForName:(id)fp8;
- (void)removeVolatileDomainForName:(id)fp8;
- (void)setObject:(id)fp8 forKey:(id)fp12;
- (void)setPersistentDomain:(id)fp8 forName:(id)fp12;
- (void)setVolatileDomain:(id)fp8 forName:(id)fp12;
- (BOOL)synchronize;
- (id)volatileDomainForName:(id)fp8;
- (id)volatileDomainNames;

@end

@interface ScreenSaverDefaultsManager : NSObject
{
    NSMutableDictionary *_cache;
}

+ (id)defaultsManager;
- (void)_appWillTerminate:(id)fp8;
- (id)defaultsForKey:(id)fp8;
- (id)init;
- (void)setDefaults:(id)fp8 forKey:(id)fp12;
- (void)synchronize;

@end

@interface ScreenSaverIPhotoAlbum : NSObject
{
    NSString *_name;
    NSString *_path;
    BOOL _isMaster;
    NSArray *_photoDicts;
}

+ (id)_albumDataXMLPath;
+ (id)albumNamed:(id)fp8;
+ (id)albumPathForName:(id)fp8;
+ (id)allAlbums;
+ (BOOL)reloadAllAlbums;
- (id)allImagePaths;
- (id)allPhotoDicts;
- (void)dealloc;
- (id)description;
- (id)imagesDirectory;
- (id)initWithName:(id)fp8 path:(id)fp12 photoDicts:(id)fp16 type:(BOOL)fp20;
- (BOOL)isMasterAlbum;
- (id)name;

@end

@interface ScreenSaverModules : NSObject
{
    NSMutableDictionary *_modules;
    NSMutableDictionary *_times;
    int _searchDomains;
    NSMutableArray *_sortedModuleNames;
    int _indexOfFirstAppleModule;
    int _indexOfLastAppleModule;
    int _indexOfChooseFolderItem;
    int _indexOfDotMacModule;
    int _indexOfPicturesFolderModule;
    int _indexOfUserSelectedFolderItem;
    int _indexOfFirstIPhotoAlbumModule;
    int _indexOfLastIPhotoAlbumModule;
    int _indexOfIPhotoLibraryAlbumModule;
    int _indexOfFirstApertureProject;
    int _indexOfLastApertureProject;
    int _indexOfApertureLibrary;
}

+ (id)sharedInstance;
- (id)_directoriesInSearchDomain;
- (id)basicModuleName;
- (int)browser:(id)fp8 numberOfRowsInColumn:(int)fp12;
- (BOOL)browser:(id)fp8 selectRow:(int)fp12 inColumn:(int)fp16;
- (void)browser:(id)fp8 willDisplayCell:(id)fp12 atRow:(int)fp16 column:(int)fp20;
- (Class)classForModuleWithName:(id)fp8;
- (Class)classForModuleWithPath:(id)fp8;
- (void)dealloc;
- (id)displayModuleNames;
- (void)findModulesWithOrder:(id)fp8;
- (int)indexOfApertureLibrary;
- (int)indexOfChooseFolderItem;
- (int)indexOfDotMacModule;
- (int)indexOfFirstApertureProject;
- (int)indexOfFirstAppleModule;
- (int)indexOfFirstIPhotoAlbumModule;
- (int)indexOfIPhotoLibraryAlbumModule;
- (int)indexOfLastApertureProject;
- (int)indexOfLastAppleModule;
- (int)indexOfLastIPhotoAlbumModule;
- (int)indexOfPicturesFolderModule;
- (int)indexOfUserSelectedFolderItem;
- (id)init;
- (id)loadModuleWithName:(id)fp8;
- (id)loadModuleWithName:(id)fp8 frame:(struct _NSRect)fp12 isPreview:(BOOL)fp28;
- (id)loadModuleWithPath:(id)fp8;
- (id)loadModuleWithPath:(id)fp8 frame:(struct _NSRect)fp12 isPreview:(BOOL)fp28;
- (id)moduleNames;
- (int)moduleSearchDomains;
- (id)pathForModuleName:(id)fp8;
- (id)pathToLastUserSelectedFolder;
- (void)setModuleSearchDomains:(int)fp8;
- (void)setUserSelectedFolderName:(id)fp8;
- (id)slideShowModuleName;

@end

@interface ScreenSaverUserInfo : NSObject
{
    unsigned int _eventHandle;
}

+ (id)sharedInstance;
- (double)idleTime;
- (id)init;
- (void)loginUserName:(id *)fp8 andID:(unsigned int *)fp12;
- (unsigned int)uidForUserName:(id)fp8;

@end

@interface ScreenSaverWindow : NSWindow
{
    NSMutableArray *_trectTags;
}

- (void)_cancelKey:(id)fp8;
- (void)_discardTrackingRect:(int)fp8;
- (int)_setTrackingRect:(struct _NSRect)fp8 inside:(BOOL)fp24 owner:(id)fp28 userData:(void *)fp32 useTrackingNum:(int)fp36;
- (BOOL)canBecomeKeyWindow;
- (BOOL)canBecomeMainWindow;
- (id)initWithContentRect:(struct _NSRect)fp8 styleMask:(unsigned int)fp24 backing:(int)fp28 defer:(BOOL)fp32;
- (void)removeAllTrackingRects;
- (void)startAnimating;
- (void)stopAnimating;

@end

