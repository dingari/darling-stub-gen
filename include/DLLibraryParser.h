/*
 This file is part of Darling.

 Copyright (C) 2021 Darling Team

 Darling is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Darling is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#import <Foundation/Foundation.h>
#import <MachOKit/MachOKit.h>

#import "DLArgumentParser.h"
#import "symbols/DLMainImage.h"
#import "symbols/objectivec/DLObjectiveCSymbols.h"


NS_ASSUME_NONNULL_BEGIN

@interface DLLibraryParser : NSObject {
    DLArgumentParser *_arguments;
    
    NSMutableArray *dependiciesList;
    NSMutableArray<NSString*> *functionsC;
}

@property(readonly) DLMainImage* mainImage;

@property(readonly) DLObjectiveCSymbols *objCSymbols;

@property(readonly) NSMutableArray<NSString*> *localUnknownSymbols;
@property(readonly) NSMutableArray<NSString*> *localIgnoreSymbols;
@property(readonly) NSMutableArray<NSString*> *externalSymbols;
@property(readonly) NSMutableArray<NSString*> *undefinedSymbols;

@property(readonly) NSMutableArray<NSString*> *functionCPP;

-(instancetype)initWithArguments:(DLArgumentParser*)arugmentParser;
-(void)parseCurrentMachOImage:(MKMachOImage*)image;
-(void)parseDependentLibraryWithMachOImage:(MKMachOImage*)image;
-(void)parseSymbolWithMachOImage:(MKMachOImage*)image;

@end

NS_ASSUME_NONNULL_END
