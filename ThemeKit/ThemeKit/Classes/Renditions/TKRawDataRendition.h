//
//  TKRawDataRendition.h
//  ThemeKit
//
//  Created by Alexander Zielenski on 6/14/15.
//  Copyright © 2015 Alex Zielenski. All rights reserved.
//

#import <ThemeKit/TKRendition.h>
extern NSString *const TKUTITypeCoreAnimationArchive;

@interface TKRawDataRendition : TKRendition
@property (nonatomic, strong) NSData *rawData;
@property (nonatomic, strong) CALayer *rootLayer;

- (NSString *)hierarchicalDebugDescriptionOfCALayer:(CALayer *)layer level:(NSUInteger)level;
- (void)logCALayerHierarchy:(CALayer *)layer level:(NSUInteger)level;

@end
