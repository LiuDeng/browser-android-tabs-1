// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/css/css_page_rule.h"

#include "third_party/blink/renderer/core/css/css_rule_list.h"
#include "third_party/blink/renderer/core/css/css_test_helpers.h"
#include "third_party/blink/renderer/core/dom/document.h"

#include "testing/gtest/include/gtest/gtest.h"

namespace blink {

using namespace css_test_helpers;

TEST(CSSPageRule, Serializing) {
  TestStyleSheet sheet;

  const char* css_rule = "@page :left { size: auto; }";
  sheet.AddCSSRules(css_rule);
  if (sheet.CssRules()) {
    EXPECT_EQ(1u, sheet.CssRules()->length());
    EXPECT_EQ(String(css_rule), sheet.CssRules()->item(0)->cssText());
    EXPECT_EQ(CSSRule::kPageRule, sheet.CssRules()->item(0)->type());
    if (CSSPageRule* page_rule = ToCSSPageRule(sheet.CssRules()->item(0)))
      EXPECT_EQ(":left", page_rule->selectorText());
  }
}

TEST(CSSPageRule, selectorText) {
  TestStyleSheet sheet;

  const char* css_rule = "@page :left { size: auto; }";
  sheet.AddCSSRules(css_rule);
  DCHECK(sheet.CssRules());
  EXPECT_EQ(1u, sheet.CssRules()->length());

  CSSPageRule* page_rule = ToCSSPageRule(sheet.CssRules()->item(0));
  EXPECT_EQ(":left", page_rule->selectorText());

  // set invalid page selector.
  page_rule->setSelectorText(&sheet.GetDocument(), ":hover");
  EXPECT_EQ(":left", page_rule->selectorText());

  // set invalid page selector.
  page_rule->setSelectorText(&sheet.GetDocument(), "right { bla");
  EXPECT_EQ(":left", page_rule->selectorText());

  // set page pseudo class selector.
  page_rule->setSelectorText(&sheet.GetDocument(), ":right");
  EXPECT_EQ(":right", page_rule->selectorText());

  // set page type selector.
  page_rule->setSelectorText(&sheet.GetDocument(), "namedpage");
  EXPECT_EQ("namedpage", page_rule->selectorText());
}

}  // namespace blink
