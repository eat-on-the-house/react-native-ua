/*
 Copyright 2009-2016 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "UAJSONMatcher.h"
#import "UAJSONValueMatcher.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents the possible error conditions when deserializing predicate from JSON.
 */
typedef NS_ENUM(NSInteger, UAJSONPredicateErrorCode) {
    /**
     * Indicates an error with the predicate JSON definition.
     */
    UAJSONPredicateErrorCodeInvalidJSON,
};

/**
 * The domain for NSErrors generated by `predicateWithJSON:error`.
 */
extern NSString * const UAJSONPredicateErrorDomain;


/**
 * Predicate for JSON payloads.
 */
@interface UAJSONPredicate : NSObject

/**
 * The predicate's JSON payload.
 */
@property(nonatomic, readonly) NSDictionary *payload;

/**
 * Evaluates the object with the predicate.
 *
 * @param object The object to evaluate.
 * @return `YES` if the predicate matches the object, otherwise `NO`.
 */
- (BOOL)evaluateObject:(nullable id)object;

/**
 * Factory method to create a JSON predicate from a UAJSONMatcher.
 *
 * @param matcher A JSON matcher.
 * @return A JSON predicate.
 */
+ (instancetype)predicateWithJSONMatcher:(UAJSONMatcher *)matcher;

/**
 * Factory method to create a JSON predicate formed by AND-ing an array of predicates.
 *
 * @param subpredicates An array of predicates.
 * @return A JSON predicate.
 */
+ (instancetype)andPredicateWithSubpredicates:(NSArray<UAJSONPredicate*>*)subpredicates;


/**
 * Factory method to create a JSON predicate formed by OR-ing an array of predicates.
 *
 * @param subpredicates An array of predicates.
 * @return A JSON predicate.
 */
+ (instancetype)orPredicateWithSubpredicates:(NSArray<UAJSONPredicate*>*)subpredicates;

/**
 * Factory method to create a JSON predicate by NOT-ing a predicate.
 *
 * @param subpredicate A predicate.
 * @return A JSON predicate.
 */
+ (instancetype)notPredicateWithSubpredicate:(UAJSONPredicate *)subpredicate;

/**
 * Factory method to create a predicate from a JSON payload.
 *
 * @param json The JSON payload.
 * @param error An NSError pointer for storing errors, if applicable.
 * @return A predicate or `nil` if the JSON is invalid.
 */
+ (nullable instancetype)predicateWithJSON:(id)json error:(NSError * _Nullable *)error;

@end

NS_ASSUME_NONNULL_END
