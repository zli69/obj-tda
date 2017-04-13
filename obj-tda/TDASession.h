//
//  TDASession.h
//  obj-tda
//
//  Created by david on 4/3/17.
//  Copyright © 2017 combobulated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TDAOrder.h"
#import "TDAQuote.h"
#import "TDAPriceHistory.h"
#import "TDABalances.h"
#import "TDAPosition.h"
#import "TDAOptionChain.h"

@interface TDASession : NSObject
{
    NSString *_source;
    NSArray *_accountIDs;
}

- (BOOL)loginWithUser:(NSString *)user pass:(NSString *)pass source:(NSString *)source version:(NSString *)version;
- (BOOL)keepAlive;
- (BOOL)logoff;

// account
- (BOOL)getBalancesAndPositions:(TDABalances **)outBalances :(NSArray **)outPositions;

// info
- (TDAQuote *)getQuote:(NSString *)symbol;
- (TDAPriceHistory *)getPriceHistory:(NSString *)symbol
                                    :(IntervalType)interval
                                    :(int)duration
                                    :(PeriodType)periodType
                                    :(int)period
                                    :(NSDate *)startDate
                                    :(NSDate *)endDate
                                    :(BOOL)extended;
- (TDAOptionChain *)getOptionChainForSymbol:(NSString *)symbol;

// orders
- (BOOL)submitOrder:(TDAOrder *)order;
- (BOOL)getOrderStatus:(TDAOrder *)order;
- (BOOL)cancelOrder:(TDAOrder *)order;

@end
