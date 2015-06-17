//
//  ALPHANetworkConnection.h
//  Alpha
//
//  Created by Dal Rupnik on 06/11/14.
//  Copyright (c) 2014 Unified Sense. All rights reserved.
//

#import "ALPHASerialization.h"

#import "ALPHANetworkRequest.h"
#import "ALPHANetworkResponse.h"
#import "ALPHANetworkConnectionTiming.h"
#import "ALPHANetworkError.h"

typedef enum : NSUInteger {
    FLEXNetworkConnectionTypeSession,
    FLEXNetworkConnectionTypeConnection,
} FLEXNetworkConnectionType;

@interface ALPHANetworkConnection : NSObject <ALPHASerializableItem>

@property (nonatomic, copy) NSString *requestID;

@property (nonatomic) FLEXNetworkConnectionType type;

@property (nonatomic, strong) ALPHANetworkRequest *request;

@property (nonatomic, strong) ALPHANetworkResponse *redirectResponse;
@property (nonatomic, strong) ALPHANetworkResponse *response;

// Timing information for the given request.
@property (nonatomic, strong) ALPHANetworkConnectionTiming *timing;

@property (nonatomic, strong) ALPHANetworkError *error;

@property (nonatomic, copy) NSData *responseData;

@property (nonatomic, readonly) NSString *responseString;

- (void)updateWithRequest:(ALPHANetworkRequest *)request withResponse:(ALPHANetworkResponse *)response;

#pragma mark - Convenience

- (NSNumber *)size;

@end
