/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */


#import <Foundation/Foundation.h>
#import "BOM.h"
#import "TKStructs.h"

struct _carextendedMetadata {
    unsigned int _field1;
    char _field2[256];
    char _field3[256];
    char _field4[256];
    char _field5[256];
};

//struct _carheader {
//    unsigned int _field1;
//    unsigned int _field2;
//    unsigned int _field3;
//    unsigned int _field4;
//    unsigned int _field5;
//    char _field6[128];
//    char _field7[256];
//    unsigned char _field8[16];
//    unsigned int _field9;
//    unsigned int _field10;
//    unsigned int _field11;
//    unsigned int _field12;
//};

struct _carheader {
    unsigned int magic; // 'CTAR'
    unsigned int coreui_version;
    unsigned int storage_version;
    unsigned int _field4;
    unsigned int renditionCount;
    char program_string[128];
    char version_string[256];
    unsigned char _field8[16];
    unsigned int associated_checksum;
    unsigned int schema_version;
    unsigned int colorspace_id;
    unsigned int key_semantics;
};

//@interface CUICommonAssetStorage : NSObject
//{
//    struct _carheader *_header;
//    struct _carextendedMetadata *_extendedMetadata;
//    struct _renditionkeyfmt *_keyfmt;
//    void *_imagedb;
//    void *_colordb;
//    void *_fontdb;
//    void *_fontsizedb;
//    void *_zcglyphdb;
//    void *_zcbezeldb;
//    void *_facetKeysdb;
//    void *_bitmapKeydb;
//    void *_appearancedb;
//    NSData *_globals;
//    unsigned int _swap:1;
//    unsigned int _isMemoryMapped:1;
//    unsigned int _reserved:30;
//    NSSet *_externalTags;
//    unsigned short _renditionInfoCacheLookup[20];
//    id _renditionInfoCache[20];
//    struct os_unfair_lock_s _lock;
//    struct os_unfair_lock_s _renditionInfoCacheLock;
//}

// Not exported
@interface CUICommonAssetStorage : NSObject
{
    struct _carheader *_header;

    struct _carextendedMetadata *_extendedMetadata;

    struct renditionkeyfmt *_keyfmt;
    // Maps rendition keys to CoreTheme Structured Images
    BOMTreeRef _imagedb;
    // Maps color names to color values
    BOMTreeRef _colordb;
    // Unknown
    BOMTreeRef _fontdb;
    // Unknown
    BOMTreeRef _fontsizedb;
    // Unknown
    BOMTreeRef _zcglyphdb;
    // Unknown
    BOMTreeRef _zcbezeldb;
    
    //  Maps rendition names to rendition keys
    // keys in this tree are facet names
    // values are lists of:
    //
    BOMTreeRef _facetKeysdb;

    BOMTreeRef _bitmapKeydb;
    
    BOMTreeRef _appearancedb;
    
    NSData *_globals;
    
        unsigned int _swap:1;
        unsigned int _isMemoryMapped:1;
        unsigned int _reserved:30;
        NSSet *_externalTags;
        unsigned short _renditionInfoCacheLookup[20];
        id _renditionInfoCache[20];
        struct os_unfair_lock_s _lock;
        struct os_unfair_lock_s _renditionInfoCacheLock;

//    BOOL _swap;
//    NSSet *_externalTags;
}

- (instancetype)initWithBytes:(const void *)bytes length:(unsigned long long)length;
- (instancetype)initWithPath:(NSString *)path forWriting:(BOOL)forWriting;
- (instancetype)initWithPath:(NSString *)path;

- (NSArray *)externalTags;
- (BOOL)hasColorForName:(const char *)name;
- (BOOL)getColor:(struct colordef *)color forName:(const char *)name;

- (NSString *)renditionNameForKeyList:(struct renditionkeytoken *)arg1;
- (NSArray *)allRenditionNames;
// You can just pass nothing for the hotspot
- (const struct renditionkeytoken *)renditionKeyForName:(const char *)arg1 hotSpot:(CGPoint)arg2;

- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(struct renditionkeytoken *keyList, NSData *csiData))block;
- (NSArray *)assetKeysMatchingBlock:(id)arg1;
- (NSArray *)allAssetKeys;
- (id)assetForKey:(NSData *)key;
- (BOOL)assetExistsForKeyData:(const void *)bytes length:(unsigned long long)length;
- (BOOL)assetExistsForKey:(NSData *)key;

- (unsigned int)colorSpaceID;
- (unsigned int)associatedChecksum;
- (NSUUID *)uuid;
- (unsigned int)renditionCount;
- (BOOL)usesCUISystemThemeRenditionKey;
- (long long)maximumRenditionKeyTokenCount;

// Encoded plist with some rendering information for this appearance
// This only applies to appearances
// Known keys:
//    allowsVibrancy, defaultBlendMode
- (NSData *)catalogGlobalData;

- (const struct renditionkeyfmt *)keyFormat;
- (NSData *)keyFormatData;
- (int)keySemantics;

- (NSString *)path;
- (BOOL)_commonInitWithStorage:(BOMStorageRef)arg1 forWritting:(BOOL)arg2;
- (BOOL)swapped;

- (const char *)versionString;
- (long long)storageTimestamp;
- (long long)_storagefileTimestamp;
- (unsigned int)schemaVersion;
- (unsigned int)coreuiVersion;
- (unsigned int)storageVersion;

- (void)_swapRenditionKeyArray:(unsigned short *)renditionKeyArray;
- (struct renditionkeytoken)_swapRenditionKeyToken:(struct renditionkeytoken)token;
- (void)_swapKeyFormat;
- (void)_swapHeader;
- (void)_bringHeaderInfoUpToDate;
- (void)_initDefaultHeaderVersion:(CGFloat)version versionString:(const char *)versionString;

//- (float)fontSizeForFontSizeType:(id)arg1;
//- (BOOL)getBaselineOffset:(float *)arg1 forFontType:(id)arg2;
//- (BOOL)getFontName:(id *)arg1 baselineOffset:(float *)arg2 forFontType:(id)arg3;
//- (const struct FontValue *)_fontValueForFontType:(id)arg1;

- (NSArray *)zeroCodeBezelList;
- (NSArray *)zeroCodeGlyphList;
//- (id)_zeroCodeListFromTree:(const void *)arg1;
//- (void)_swapZeroCodeInformation:(CDStruct_c0454aff *)arg1;

@end

