
// Generated from RDFTESLA.g4 by ANTLR 4.6


#include "RDFTESLAListener.h"

#include "RDFTESLAParser.h"


using namespace antlrcpp;
using namespace antlr4;

RDFTESLAParser::RDFTESLAParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RDFTESLAParser::~RDFTESLAParser() {
  delete _interpreter;
}

std::string RDFTESLAParser::getGrammarFileName() const {
  return "RDFTESLA.g4";
}

const std::vector<std::string>& RDFTESLAParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RDFTESLAParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Static_referenceContext ------------------------------------------------------------------

RDFTESLAParser::Static_referenceContext::Static_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Static_referenceContext::INT_VAL() {
  return getToken(RDFTESLAParser::INT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Static_referenceContext::FLOAT_VAL() {
  return getToken(RDFTESLAParser::FLOAT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Static_referenceContext::STRING_VAL() {
  return getToken(RDFTESLAParser::STRING_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Static_referenceContext::BOOL_VAL() {
  return getToken(RDFTESLAParser::BOOL_VAL, 0);
}


size_t RDFTESLAParser::Static_referenceContext::getRuleIndex() const {
  return RDFTESLAParser::RuleStatic_reference;
}

void RDFTESLAParser::Static_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatic_reference(this);
}

void RDFTESLAParser::Static_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatic_reference(this);
}

RDFTESLAParser::Static_referenceContext* RDFTESLAParser::static_reference() {
  Static_referenceContext *_localctx = _tracker.createInstance<Static_referenceContext>(_ctx, getState());
  enterRule(_localctx, 0, RDFTESLAParser::RuleStatic_reference);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RDFTESLAParser::INT_VAL)
      | (1ULL << RDFTESLAParser::FLOAT_VAL)
      | (1ULL << RDFTESLAParser::BOOL_VAL)
      | (1ULL << RDFTESLAParser::STRING_VAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Packet_referenceContext ------------------------------------------------------------------

RDFTESLAParser::Packet_referenceContext::Packet_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Packet_referenceContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}

tree::TerminalNode* RDFTESLAParser::Packet_referenceContext::SPARQL_VAR() {
  return getToken(RDFTESLAParser::SPARQL_VAR, 0);
}


size_t RDFTESLAParser::Packet_referenceContext::getRuleIndex() const {
  return RDFTESLAParser::RulePacket_reference;
}

void RDFTESLAParser::Packet_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPacket_reference(this);
}

void RDFTESLAParser::Packet_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPacket_reference(this);
}

RDFTESLAParser::Packet_referenceContext* RDFTESLAParser::packet_reference() {
  Packet_referenceContext *_localctx = _tracker.createInstance<Packet_referenceContext>(_ctx, getState());
  enterRule(_localctx, 2, RDFTESLAParser::RulePacket_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(RDFTESLAParser::EVT_NAME);
    setState(71);
    match(RDFTESLAParser::T__0);
    setState(72);
    match(RDFTESLAParser::SPARQL_VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_atomContext ------------------------------------------------------------------

RDFTESLAParser::Param_atomContext::Param_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::Packet_referenceContext* RDFTESLAParser::Param_atomContext::packet_reference() {
  return getRuleContext<RDFTESLAParser::Packet_referenceContext>(0);
}

RDFTESLAParser::Static_referenceContext* RDFTESLAParser::Param_atomContext::static_reference() {
  return getRuleContext<RDFTESLAParser::Static_referenceContext>(0);
}


size_t RDFTESLAParser::Param_atomContext::getRuleIndex() const {
  return RDFTESLAParser::RuleParam_atom;
}

void RDFTESLAParser::Param_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_atom(this);
}

void RDFTESLAParser::Param_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_atom(this);
}

RDFTESLAParser::Param_atomContext* RDFTESLAParser::param_atom() {
  Param_atomContext *_localctx = _tracker.createInstance<Param_atomContext>(_ctx, getState());
  enterRule(_localctx, 4, RDFTESLAParser::RuleParam_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::EVT_NAME: {
        setState(74);
        packet_reference();
        break;
      }

      case RDFTESLAParser::INT_VAL:
      case RDFTESLAParser::FLOAT_VAL:
      case RDFTESLAParser::BOOL_VAL:
      case RDFTESLAParser::STRING_VAL: {
        setState(75);
        static_reference();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Agg_one_referenceContext ------------------------------------------------------------------

RDFTESLAParser::Agg_one_referenceContext::Agg_one_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Agg_one_referenceContext::INT_VAL() {
  return getToken(RDFTESLAParser::INT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Agg_one_referenceContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}


size_t RDFTESLAParser::Agg_one_referenceContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAgg_one_reference;
}

void RDFTESLAParser::Agg_one_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgg_one_reference(this);
}

void RDFTESLAParser::Agg_one_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgg_one_reference(this);
}

RDFTESLAParser::Agg_one_referenceContext* RDFTESLAParser::agg_one_reference() {
  Agg_one_referenceContext *_localctx = _tracker.createInstance<Agg_one_referenceContext>(_ctx, getState());
  enterRule(_localctx, 6, RDFTESLAParser::RuleAgg_one_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(RDFTESLAParser::T__1);
    setState(79);
    match(RDFTESLAParser::INT_VAL);
    setState(80);
    match(RDFTESLAParser::T__2);
    setState(81);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Agg_betweenContext ------------------------------------------------------------------

RDFTESLAParser::Agg_betweenContext::Agg_betweenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RDFTESLAParser::Agg_betweenContext::EVT_NAME() {
  return getTokens(RDFTESLAParser::EVT_NAME);
}

tree::TerminalNode* RDFTESLAParser::Agg_betweenContext::EVT_NAME(size_t i) {
  return getToken(RDFTESLAParser::EVT_NAME, i);
}


size_t RDFTESLAParser::Agg_betweenContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAgg_between;
}

void RDFTESLAParser::Agg_betweenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgg_between(this);
}

void RDFTESLAParser::Agg_betweenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgg_between(this);
}

RDFTESLAParser::Agg_betweenContext* RDFTESLAParser::agg_between() {
  Agg_betweenContext *_localctx = _tracker.createInstance<Agg_betweenContext>(_ctx, getState());
  enterRule(_localctx, 8, RDFTESLAParser::RuleAgg_between);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(RDFTESLAParser::T__3);
    setState(84);
    match(RDFTESLAParser::EVT_NAME);
    setState(85);
    match(RDFTESLAParser::T__4);
    setState(86);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregate_atomContext ------------------------------------------------------------------

RDFTESLAParser::Aggregate_atomContext::Aggregate_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Aggregate_atomContext::AGGR_FUN() {
  return getToken(RDFTESLAParser::AGGR_FUN, 0);
}

RDFTESLAParser::Packet_referenceContext* RDFTESLAParser::Aggregate_atomContext::packet_reference() {
  return getRuleContext<RDFTESLAParser::Packet_referenceContext>(0);
}

RDFTESLAParser::Agg_one_referenceContext* RDFTESLAParser::Aggregate_atomContext::agg_one_reference() {
  return getRuleContext<RDFTESLAParser::Agg_one_referenceContext>(0);
}

RDFTESLAParser::Agg_betweenContext* RDFTESLAParser::Aggregate_atomContext::agg_between() {
  return getRuleContext<RDFTESLAParser::Agg_betweenContext>(0);
}

std::vector<RDFTESLAParser::Attr_parameterContext *> RDFTESLAParser::Aggregate_atomContext::attr_parameter() {
  return getRuleContexts<RDFTESLAParser::Attr_parameterContext>();
}

RDFTESLAParser::Attr_parameterContext* RDFTESLAParser::Aggregate_atomContext::attr_parameter(size_t i) {
  return getRuleContext<RDFTESLAParser::Attr_parameterContext>(i);
}

std::vector<RDFTESLAParser::Attr_constraintContext *> RDFTESLAParser::Aggregate_atomContext::attr_constraint() {
  return getRuleContexts<RDFTESLAParser::Attr_constraintContext>();
}

RDFTESLAParser::Attr_constraintContext* RDFTESLAParser::Aggregate_atomContext::attr_constraint(size_t i) {
  return getRuleContext<RDFTESLAParser::Attr_constraintContext>(i);
}


size_t RDFTESLAParser::Aggregate_atomContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAggregate_atom;
}

void RDFTESLAParser::Aggregate_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_atom(this);
}

void RDFTESLAParser::Aggregate_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_atom(this);
}

RDFTESLAParser::Aggregate_atomContext* RDFTESLAParser::aggregate_atom() {
  Aggregate_atomContext *_localctx = _tracker.createInstance<Aggregate_atomContext>(_ctx, getState());
  enterRule(_localctx, 10, RDFTESLAParser::RuleAggregate_atom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(RDFTESLAParser::AGGR_FUN);
    setState(89);
    match(RDFTESLAParser::T__5);
    setState(90);
    packet_reference();
    setState(91);
    match(RDFTESLAParser::T__5);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RDFTESLAParser::T__9

    || _la == RDFTESLAParser::SPARQL_VAR) {
      setState(94);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RDFTESLAParser::T__9: {
          setState(92);
          attr_parameter();
          break;
        }

        case RDFTESLAParser::SPARQL_VAR: {
          setState(93);
          attr_constraint();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RDFTESLAParser::T__6) {
        setState(96);
        match(RDFTESLAParser::T__6);
        setState(99);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case RDFTESLAParser::T__9: {
            setState(97);
            attr_parameter();
            break;
          }

          case RDFTESLAParser::SPARQL_VAR: {
            setState(98);
            attr_constraint();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(108);
    match(RDFTESLAParser::T__7);
    setState(109);
    match(RDFTESLAParser::T__7);
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__1: {
        setState(110);
        agg_one_reference();
        break;
      }

      case RDFTESLAParser::T__3: {
        setState(111);
        agg_between();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

RDFTESLAParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RDFTESLAParser::ExprContext *> RDFTESLAParser::ExprContext::expr() {
  return getRuleContexts<RDFTESLAParser::ExprContext>();
}

RDFTESLAParser::ExprContext* RDFTESLAParser::ExprContext::expr(size_t i) {
  return getRuleContext<RDFTESLAParser::ExprContext>(i);
}

RDFTESLAParser::Param_atomContext* RDFTESLAParser::ExprContext::param_atom() {
  return getRuleContext<RDFTESLAParser::Param_atomContext>(0);
}

RDFTESLAParser::Aggregate_atomContext* RDFTESLAParser::ExprContext::aggregate_atom() {
  return getRuleContext<RDFTESLAParser::Aggregate_atomContext>(0);
}

tree::TerminalNode* RDFTESLAParser::ExprContext::BINOP_MUL() {
  return getToken(RDFTESLAParser::BINOP_MUL, 0);
}

tree::TerminalNode* RDFTESLAParser::ExprContext::BINOP_ADD() {
  return getToken(RDFTESLAParser::BINOP_ADD, 0);
}


size_t RDFTESLAParser::ExprContext::getRuleIndex() const {
  return RDFTESLAParser::RuleExpr;
}

void RDFTESLAParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void RDFTESLAParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


RDFTESLAParser::ExprContext* RDFTESLAParser::expr() {
   return expr(0);
}

RDFTESLAParser::ExprContext* RDFTESLAParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RDFTESLAParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  RDFTESLAParser::ExprContext *previousContext = _localctx;
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, RDFTESLAParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__5: {
        setState(115);
        match(RDFTESLAParser::T__5);
        setState(116);
        expr(0);
        setState(117);
        match(RDFTESLAParser::T__7);
        break;
      }

      case RDFTESLAParser::AGGR_FUN:
      case RDFTESLAParser::INT_VAL:
      case RDFTESLAParser::FLOAT_VAL:
      case RDFTESLAParser::BOOL_VAL:
      case RDFTESLAParser::STRING_VAL:
      case RDFTESLAParser::EVT_NAME: {
        setState(121);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case RDFTESLAParser::INT_VAL:
          case RDFTESLAParser::FLOAT_VAL:
          case RDFTESLAParser::BOOL_VAL:
          case RDFTESLAParser::STRING_VAL:
          case RDFTESLAParser::EVT_NAME: {
            setState(119);
            param_atom();
            break;
          }

          case RDFTESLAParser::AGGR_FUN: {
            setState(120);
            aggregate_atom();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(133);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(131);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(125);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(126);
          match(RDFTESLAParser::BINOP_MUL);
          setState(127);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(128);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(129);
          match(RDFTESLAParser::BINOP_ADD);
          setState(130);
          expr(4);
          break;
        }

        } 
      }
      setState(135);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StaticAttr_definitionContext ------------------------------------------------------------------

RDFTESLAParser::StaticAttr_definitionContext::StaticAttr_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::StaticAttr_definitionContext::SPARQL_VAR() {
  return getToken(RDFTESLAParser::SPARQL_VAR, 0);
}

RDFTESLAParser::Static_referenceContext* RDFTESLAParser::StaticAttr_definitionContext::static_reference() {
  return getRuleContext<RDFTESLAParser::Static_referenceContext>(0);
}


size_t RDFTESLAParser::StaticAttr_definitionContext::getRuleIndex() const {
  return RDFTESLAParser::RuleStaticAttr_definition;
}

void RDFTESLAParser::StaticAttr_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticAttr_definition(this);
}

void RDFTESLAParser::StaticAttr_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticAttr_definition(this);
}

RDFTESLAParser::StaticAttr_definitionContext* RDFTESLAParser::staticAttr_definition() {
  StaticAttr_definitionContext *_localctx = _tracker.createInstance<StaticAttr_definitionContext>(_ctx, getState());
  enterRule(_localctx, 14, RDFTESLAParser::RuleStaticAttr_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(RDFTESLAParser::SPARQL_VAR);
    setState(137);
    match(RDFTESLAParser::T__8);
    setState(138);
    static_reference();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_definitionContext ------------------------------------------------------------------

RDFTESLAParser::Attr_definitionContext::Attr_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Attr_definitionContext::SPARQL_VAR() {
  return getToken(RDFTESLAParser::SPARQL_VAR, 0);
}

RDFTESLAParser::ExprContext* RDFTESLAParser::Attr_definitionContext::expr() {
  return getRuleContext<RDFTESLAParser::ExprContext>(0);
}


size_t RDFTESLAParser::Attr_definitionContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAttr_definition;
}

void RDFTESLAParser::Attr_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_definition(this);
}

void RDFTESLAParser::Attr_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_definition(this);
}

RDFTESLAParser::Attr_definitionContext* RDFTESLAParser::attr_definition() {
  Attr_definitionContext *_localctx = _tracker.createInstance<Attr_definitionContext>(_ctx, getState());
  enterRule(_localctx, 16, RDFTESLAParser::RuleAttr_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(RDFTESLAParser::SPARQL_VAR);
    setState(141);
    match(RDFTESLAParser::T__8);
    setState(142);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_constraintContext ------------------------------------------------------------------

RDFTESLAParser::Attr_constraintContext::Attr_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Attr_constraintContext::SPARQL_VAR() {
  return getToken(RDFTESLAParser::SPARQL_VAR, 0);
}

tree::TerminalNode* RDFTESLAParser::Attr_constraintContext::OPERATOR() {
  return getToken(RDFTESLAParser::OPERATOR, 0);
}

RDFTESLAParser::Static_referenceContext* RDFTESLAParser::Attr_constraintContext::static_reference() {
  return getRuleContext<RDFTESLAParser::Static_referenceContext>(0);
}


size_t RDFTESLAParser::Attr_constraintContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAttr_constraint;
}

void RDFTESLAParser::Attr_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_constraint(this);
}

void RDFTESLAParser::Attr_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_constraint(this);
}

RDFTESLAParser::Attr_constraintContext* RDFTESLAParser::attr_constraint() {
  Attr_constraintContext *_localctx = _tracker.createInstance<Attr_constraintContext>(_ctx, getState());
  enterRule(_localctx, 18, RDFTESLAParser::RuleAttr_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(RDFTESLAParser::SPARQL_VAR);
    setState(145);
    match(RDFTESLAParser::OPERATOR);
    setState(146);
    static_reference();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_parameterContext ------------------------------------------------------------------

RDFTESLAParser::Attr_parameterContext::Attr_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Attr_parameterContext::VALTYPE() {
  return getToken(RDFTESLAParser::VALTYPE, 0);
}

tree::TerminalNode* RDFTESLAParser::Attr_parameterContext::SPARQL_VAR() {
  return getToken(RDFTESLAParser::SPARQL_VAR, 0);
}

tree::TerminalNode* RDFTESLAParser::Attr_parameterContext::OPERATOR() {
  return getToken(RDFTESLAParser::OPERATOR, 0);
}

RDFTESLAParser::ExprContext* RDFTESLAParser::Attr_parameterContext::expr() {
  return getRuleContext<RDFTESLAParser::ExprContext>(0);
}


size_t RDFTESLAParser::Attr_parameterContext::getRuleIndex() const {
  return RDFTESLAParser::RuleAttr_parameter;
}

void RDFTESLAParser::Attr_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_parameter(this);
}

void RDFTESLAParser::Attr_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_parameter(this);
}

RDFTESLAParser::Attr_parameterContext* RDFTESLAParser::attr_parameter() {
  Attr_parameterContext *_localctx = _tracker.createInstance<Attr_parameterContext>(_ctx, getState());
  enterRule(_localctx, 20, RDFTESLAParser::RuleAttr_parameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(RDFTESLAParser::T__9);
    setState(149);
    match(RDFTESLAParser::VALTYPE);
    setState(150);
    match(RDFTESLAParser::T__10);
    setState(151);
    match(RDFTESLAParser::SPARQL_VAR);
    setState(152);
    match(RDFTESLAParser::OPERATOR);
    setState(153);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicateContext ------------------------------------------------------------------

RDFTESLAParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::PredicateContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}

tree::TerminalNode* RDFTESLAParser::PredicateContext::SPARQL_QUERY() {
  return getToken(RDFTESLAParser::SPARQL_QUERY, 0);
}

RDFTESLAParser::Event_aliasContext* RDFTESLAParser::PredicateContext::event_alias() {
  return getRuleContext<RDFTESLAParser::Event_aliasContext>(0);
}


size_t RDFTESLAParser::PredicateContext::getRuleIndex() const {
  return RDFTESLAParser::RulePredicate;
}

void RDFTESLAParser::PredicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredicate(this);
}

void RDFTESLAParser::PredicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredicate(this);
}

RDFTESLAParser::PredicateContext* RDFTESLAParser::predicate() {
  PredicateContext *_localctx = _tracker.createInstance<PredicateContext>(_ctx, getState());
  enterRule(_localctx, 22, RDFTESLAParser::RulePredicate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(RDFTESLAParser::EVT_NAME);
    setState(156);
    match(RDFTESLAParser::T__8);
    setState(157);
    match(RDFTESLAParser::SPARQL_QUERY);
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RDFTESLAParser::T__11) {
      setState(158);
      event_alias();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_aliasContext ------------------------------------------------------------------

RDFTESLAParser::Event_aliasContext::Event_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Event_aliasContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}


size_t RDFTESLAParser::Event_aliasContext::getRuleIndex() const {
  return RDFTESLAParser::RuleEvent_alias;
}

void RDFTESLAParser::Event_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEvent_alias(this);
}

void RDFTESLAParser::Event_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEvent_alias(this);
}

RDFTESLAParser::Event_aliasContext* RDFTESLAParser::event_alias() {
  Event_aliasContext *_localctx = _tracker.createInstance<Event_aliasContext>(_ctx, getState());
  enterRule(_localctx, 24, RDFTESLAParser::RuleEvent_alias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(RDFTESLAParser::T__11);
    setState(162);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TerminatorContext ------------------------------------------------------------------

RDFTESLAParser::TerminatorContext::TerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::PredicateContext* RDFTESLAParser::TerminatorContext::predicate() {
  return getRuleContext<RDFTESLAParser::PredicateContext>(0);
}


size_t RDFTESLAParser::TerminatorContext::getRuleIndex() const {
  return RDFTESLAParser::RuleTerminator;
}

void RDFTESLAParser::TerminatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerminator(this);
}

void RDFTESLAParser::TerminatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerminator(this);
}

RDFTESLAParser::TerminatorContext* RDFTESLAParser::terminator() {
  TerminatorContext *_localctx = _tracker.createInstance<TerminatorContext>(_ctx, getState());
  enterRule(_localctx, 26, RDFTESLAParser::RuleTerminator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    predicate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Positive_predicateContext ------------------------------------------------------------------

RDFTESLAParser::Positive_predicateContext::Positive_predicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Positive_predicateContext::SEL_POLICY() {
  return getToken(RDFTESLAParser::SEL_POLICY, 0);
}

RDFTESLAParser::PredicateContext* RDFTESLAParser::Positive_predicateContext::predicate() {
  return getRuleContext<RDFTESLAParser::PredicateContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Positive_predicateContext::INT_VAL() {
  return getToken(RDFTESLAParser::INT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Positive_predicateContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}


size_t RDFTESLAParser::Positive_predicateContext::getRuleIndex() const {
  return RDFTESLAParser::RulePositive_predicate;
}

void RDFTESLAParser::Positive_predicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositive_predicate(this);
}

void RDFTESLAParser::Positive_predicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositive_predicate(this);
}

RDFTESLAParser::Positive_predicateContext* RDFTESLAParser::positive_predicate() {
  Positive_predicateContext *_localctx = _tracker.createInstance<Positive_predicateContext>(_ctx, getState());
  enterRule(_localctx, 28, RDFTESLAParser::RulePositive_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(RDFTESLAParser::T__4);
    setState(167);
    match(RDFTESLAParser::SEL_POLICY);
    setState(168);
    predicate();
    setState(169);
    match(RDFTESLAParser::T__1);
    setState(170);
    match(RDFTESLAParser::INT_VAL);
    setState(171);
    match(RDFTESLAParser::T__2);
    setState(172);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Neg_one_referenceContext ------------------------------------------------------------------

RDFTESLAParser::Neg_one_referenceContext::Neg_one_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Neg_one_referenceContext::INT_VAL() {
  return getToken(RDFTESLAParser::INT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Neg_one_referenceContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}


size_t RDFTESLAParser::Neg_one_referenceContext::getRuleIndex() const {
  return RDFTESLAParser::RuleNeg_one_reference;
}

void RDFTESLAParser::Neg_one_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeg_one_reference(this);
}

void RDFTESLAParser::Neg_one_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeg_one_reference(this);
}

RDFTESLAParser::Neg_one_referenceContext* RDFTESLAParser::neg_one_reference() {
  Neg_one_referenceContext *_localctx = _tracker.createInstance<Neg_one_referenceContext>(_ctx, getState());
  enterRule(_localctx, 30, RDFTESLAParser::RuleNeg_one_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(RDFTESLAParser::T__1);
    setState(175);
    match(RDFTESLAParser::INT_VAL);
    setState(176);
    match(RDFTESLAParser::T__2);
    setState(177);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Neg_betweenContext ------------------------------------------------------------------

RDFTESLAParser::Neg_betweenContext::Neg_betweenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RDFTESLAParser::Neg_betweenContext::EVT_NAME() {
  return getTokens(RDFTESLAParser::EVT_NAME);
}

tree::TerminalNode* RDFTESLAParser::Neg_betweenContext::EVT_NAME(size_t i) {
  return getToken(RDFTESLAParser::EVT_NAME, i);
}


size_t RDFTESLAParser::Neg_betweenContext::getRuleIndex() const {
  return RDFTESLAParser::RuleNeg_between;
}

void RDFTESLAParser::Neg_betweenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeg_between(this);
}

void RDFTESLAParser::Neg_betweenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeg_between(this);
}

RDFTESLAParser::Neg_betweenContext* RDFTESLAParser::neg_between() {
  Neg_betweenContext *_localctx = _tracker.createInstance<Neg_betweenContext>(_ctx, getState());
  enterRule(_localctx, 32, RDFTESLAParser::RuleNeg_between);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    match(RDFTESLAParser::T__3);
    setState(180);
    match(RDFTESLAParser::EVT_NAME);
    setState(181);
    match(RDFTESLAParser::T__4);
    setState(182);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Negative_predicateContext ------------------------------------------------------------------

RDFTESLAParser::Negative_predicateContext::Negative_predicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::PredicateContext* RDFTESLAParser::Negative_predicateContext::predicate() {
  return getRuleContext<RDFTESLAParser::PredicateContext>(0);
}

RDFTESLAParser::Neg_one_referenceContext* RDFTESLAParser::Negative_predicateContext::neg_one_reference() {
  return getRuleContext<RDFTESLAParser::Neg_one_referenceContext>(0);
}

RDFTESLAParser::Neg_betweenContext* RDFTESLAParser::Negative_predicateContext::neg_between() {
  return getRuleContext<RDFTESLAParser::Neg_betweenContext>(0);
}


size_t RDFTESLAParser::Negative_predicateContext::getRuleIndex() const {
  return RDFTESLAParser::RuleNegative_predicate;
}

void RDFTESLAParser::Negative_predicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegative_predicate(this);
}

void RDFTESLAParser::Negative_predicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegative_predicate(this);
}

RDFTESLAParser::Negative_predicateContext* RDFTESLAParser::negative_predicate() {
  Negative_predicateContext *_localctx = _tracker.createInstance<Negative_predicateContext>(_ctx, getState());
  enterRule(_localctx, 34, RDFTESLAParser::RuleNegative_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(RDFTESLAParser::T__4);
    setState(185);
    match(RDFTESLAParser::T__12);
    setState(186);
    predicate();
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__1: {
        setState(187);
        neg_one_reference();
        break;
      }

      case RDFTESLAParser::T__3: {
        setState(188);
        neg_between();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Between_predicateContext ------------------------------------------------------------------

RDFTESLAParser::Between_predicateContext::Between_predicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RDFTESLAParser::Between_predicateContext::EVT_NAME() {
  return getTokens(RDFTESLAParser::EVT_NAME);
}

tree::TerminalNode* RDFTESLAParser::Between_predicateContext::EVT_NAME(size_t i) {
  return getToken(RDFTESLAParser::EVT_NAME, i);
}


size_t RDFTESLAParser::Between_predicateContext::getRuleIndex() const {
  return RDFTESLAParser::RuleBetween_predicate;
}

void RDFTESLAParser::Between_predicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBetween_predicate(this);
}

void RDFTESLAParser::Between_predicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBetween_predicate(this);
}

RDFTESLAParser::Between_predicateContext* RDFTESLAParser::between_predicate() {
  Between_predicateContext *_localctx = _tracker.createInstance<Between_predicateContext>(_ctx, getState());
  enterRule(_localctx, 36, RDFTESLAParser::RuleBetween_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(RDFTESLAParser::T__3);
    setState(192);
    match(RDFTESLAParser::EVT_NAME);
    setState(193);
    match(RDFTESLAParser::T__4);
    setState(194);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pattern_predicateContext ------------------------------------------------------------------

RDFTESLAParser::Pattern_predicateContext::Pattern_predicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::Positive_predicateContext* RDFTESLAParser::Pattern_predicateContext::positive_predicate() {
  return getRuleContext<RDFTESLAParser::Positive_predicateContext>(0);
}

RDFTESLAParser::Negative_predicateContext* RDFTESLAParser::Pattern_predicateContext::negative_predicate() {
  return getRuleContext<RDFTESLAParser::Negative_predicateContext>(0);
}


size_t RDFTESLAParser::Pattern_predicateContext::getRuleIndex() const {
  return RDFTESLAParser::RulePattern_predicate;
}

void RDFTESLAParser::Pattern_predicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern_predicate(this);
}

void RDFTESLAParser::Pattern_predicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern_predicate(this);
}

RDFTESLAParser::Pattern_predicateContext* RDFTESLAParser::pattern_predicate() {
  Pattern_predicateContext *_localctx = _tracker.createInstance<Pattern_predicateContext>(_ctx, getState());
  enterRule(_localctx, 38, RDFTESLAParser::RulePattern_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(196);
      positive_predicate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(197);
      negative_predicate();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pattern_b_predicateContext ------------------------------------------------------------------

RDFTESLAParser::Pattern_b_predicateContext::Pattern_b_predicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::Positive_predicateContext* RDFTESLAParser::Pattern_b_predicateContext::positive_predicate() {
  return getRuleContext<RDFTESLAParser::Positive_predicateContext>(0);
}

RDFTESLAParser::Between_predicateContext* RDFTESLAParser::Pattern_b_predicateContext::between_predicate() {
  return getRuleContext<RDFTESLAParser::Between_predicateContext>(0);
}

RDFTESLAParser::Negative_predicateContext* RDFTESLAParser::Pattern_b_predicateContext::negative_predicate() {
  return getRuleContext<RDFTESLAParser::Negative_predicateContext>(0);
}


size_t RDFTESLAParser::Pattern_b_predicateContext::getRuleIndex() const {
  return RDFTESLAParser::RulePattern_b_predicate;
}

void RDFTESLAParser::Pattern_b_predicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern_b_predicate(this);
}

void RDFTESLAParser::Pattern_b_predicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern_b_predicate(this);
}

RDFTESLAParser::Pattern_b_predicateContext* RDFTESLAParser::pattern_b_predicate() {
  Pattern_b_predicateContext *_localctx = _tracker.createInstance<Pattern_b_predicateContext>(_ctx, getState());
  enterRule(_localctx, 40, RDFTESLAParser::RulePattern_b_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(200);
      positive_predicate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      between_predicate();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(202);
      negative_predicate();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_declarationContext ------------------------------------------------------------------

RDFTESLAParser::Event_declarationContext::Event_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Event_declarationContext::INT_VAL() {
  return getToken(RDFTESLAParser::INT_VAL, 0);
}

tree::TerminalNode* RDFTESLAParser::Event_declarationContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}


size_t RDFTESLAParser::Event_declarationContext::getRuleIndex() const {
  return RDFTESLAParser::RuleEvent_declaration;
}

void RDFTESLAParser::Event_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEvent_declaration(this);
}

void RDFTESLAParser::Event_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEvent_declaration(this);
}

RDFTESLAParser::Event_declarationContext* RDFTESLAParser::event_declaration() {
  Event_declarationContext *_localctx = _tracker.createInstance<Event_declarationContext>(_ctx, getState());
  enterRule(_localctx, 42, RDFTESLAParser::RuleEvent_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(RDFTESLAParser::INT_VAL);
    setState(206);
    match(RDFTESLAParser::T__13);
    setState(207);
    match(RDFTESLAParser::EVT_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_declarationsContext ------------------------------------------------------------------

RDFTESLAParser::Event_declarationsContext::Event_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RDFTESLAParser::Event_declarationContext *> RDFTESLAParser::Event_declarationsContext::event_declaration() {
  return getRuleContexts<RDFTESLAParser::Event_declarationContext>();
}

RDFTESLAParser::Event_declarationContext* RDFTESLAParser::Event_declarationsContext::event_declaration(size_t i) {
  return getRuleContext<RDFTESLAParser::Event_declarationContext>(i);
}


size_t RDFTESLAParser::Event_declarationsContext::getRuleIndex() const {
  return RDFTESLAParser::RuleEvent_declarations;
}

void RDFTESLAParser::Event_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEvent_declarations(this);
}

void RDFTESLAParser::Event_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEvent_declarations(this);
}

RDFTESLAParser::Event_declarationsContext* RDFTESLAParser::event_declarations() {
  Event_declarationsContext *_localctx = _tracker.createInstance<Event_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 44, RDFTESLAParser::RuleEvent_declarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    event_declaration();
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RDFTESLAParser::T__6) {
      setState(210);
      match(RDFTESLAParser::T__6);
      setState(211);
      event_declaration();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Prefix_uriContext ------------------------------------------------------------------

RDFTESLAParser::Prefix_uriContext::Prefix_uriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RDFTESLAParser::Prefix_uriContext::URI_NAME() {
  return getTokens(RDFTESLAParser::URI_NAME);
}

tree::TerminalNode* RDFTESLAParser::Prefix_uriContext::URI_NAME(size_t i) {
  return getToken(RDFTESLAParser::URI_NAME, i);
}


size_t RDFTESLAParser::Prefix_uriContext::getRuleIndex() const {
  return RDFTESLAParser::RulePrefix_uri;
}

void RDFTESLAParser::Prefix_uriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefix_uri(this);
}

void RDFTESLAParser::Prefix_uriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefix_uri(this);
}

RDFTESLAParser::Prefix_uriContext* RDFTESLAParser::prefix_uri() {
  Prefix_uriContext *_localctx = _tracker.createInstance<Prefix_uriContext>(_ctx, getState());
  enterRule(_localctx, 46, RDFTESLAParser::RulePrefix_uri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(RDFTESLAParser::URI_NAME);
    setState(218);
    match(RDFTESLAParser::T__14);
    setState(219);
    match(RDFTESLAParser::URI_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Full_uriContext ------------------------------------------------------------------

RDFTESLAParser::Full_uriContext::Full_uriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Full_uriContext::URI_NAME() {
  return getToken(RDFTESLAParser::URI_NAME, 0);
}


size_t RDFTESLAParser::Full_uriContext::getRuleIndex() const {
  return RDFTESLAParser::RuleFull_uri;
}

void RDFTESLAParser::Full_uriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFull_uri(this);
}

void RDFTESLAParser::Full_uriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFull_uri(this);
}

RDFTESLAParser::Full_uriContext* RDFTESLAParser::full_uri() {
  Full_uriContext *_localctx = _tracker.createInstance<Full_uriContext>(_ctx, getState());
  enterRule(_localctx, 48, RDFTESLAParser::RuleFull_uri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(RDFTESLAParser::T__15);
    setState(222);
    match(RDFTESLAParser::URI_NAME);
    setState(223);
    match(RDFTESLAParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriContext ------------------------------------------------------------------

RDFTESLAParser::UriContext::UriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::Prefix_uriContext* RDFTESLAParser::UriContext::prefix_uri() {
  return getRuleContext<RDFTESLAParser::Prefix_uriContext>(0);
}

RDFTESLAParser::Full_uriContext* RDFTESLAParser::UriContext::full_uri() {
  return getRuleContext<RDFTESLAParser::Full_uriContext>(0);
}


size_t RDFTESLAParser::UriContext::getRuleIndex() const {
  return RDFTESLAParser::RuleUri;
}

void RDFTESLAParser::UriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUri(this);
}

void RDFTESLAParser::UriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUri(this);
}

RDFTESLAParser::UriContext* RDFTESLAParser::uri() {
  UriContext *_localctx = _tracker.createInstance<UriContext>(_ctx, getState());
  enterRule(_localctx, 50, RDFTESLAParser::RuleUri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::URI_NAME: {
        enterOuterAlt(_localctx, 1);
        setState(225);
        prefix_uri();
        break;
      }

      case RDFTESLAParser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(226);
        full_uri();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TripleContext ------------------------------------------------------------------

RDFTESLAParser::TripleContext::TripleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RDFTESLAParser::UriContext *> RDFTESLAParser::TripleContext::uri() {
  return getRuleContexts<RDFTESLAParser::UriContext>();
}

RDFTESLAParser::UriContext* RDFTESLAParser::TripleContext::uri(size_t i) {
  return getRuleContext<RDFTESLAParser::UriContext>(i);
}

std::vector<tree::TerminalNode *> RDFTESLAParser::TripleContext::SPARQL_VAR() {
  return getTokens(RDFTESLAParser::SPARQL_VAR);
}

tree::TerminalNode* RDFTESLAParser::TripleContext::SPARQL_VAR(size_t i) {
  return getToken(RDFTESLAParser::SPARQL_VAR, i);
}


size_t RDFTESLAParser::TripleContext::getRuleIndex() const {
  return RDFTESLAParser::RuleTriple;
}

void RDFTESLAParser::TripleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriple(this);
}

void RDFTESLAParser::TripleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriple(this);
}

RDFTESLAParser::TripleContext* RDFTESLAParser::triple() {
  TripleContext *_localctx = _tracker.createInstance<TripleContext>(_ctx, getState());
  enterRule(_localctx, 52, RDFTESLAParser::RuleTriple);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__15:
      case RDFTESLAParser::URI_NAME: {
        setState(229);
        uri();
        break;
      }

      case RDFTESLAParser::SPARQL_VAR: {
        setState(230);
        match(RDFTESLAParser::SPARQL_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__15:
      case RDFTESLAParser::URI_NAME: {
        setState(233);
        uri();
        break;
      }

      case RDFTESLAParser::SPARQL_VAR: {
        setState(234);
        match(RDFTESLAParser::SPARQL_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RDFTESLAParser::T__15:
      case RDFTESLAParser::URI_NAME: {
        setState(237);
        uri();
        break;
      }

      case RDFTESLAParser::SPARQL_VAR: {
        setState(238);
        match(RDFTESLAParser::SPARQL_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(241);
    match(RDFTESLAParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rdf_patternContext ------------------------------------------------------------------

RDFTESLAParser::Rdf_patternContext::Rdf_patternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RDFTESLAParser::TripleContext *> RDFTESLAParser::Rdf_patternContext::triple() {
  return getRuleContexts<RDFTESLAParser::TripleContext>();
}

RDFTESLAParser::TripleContext* RDFTESLAParser::Rdf_patternContext::triple(size_t i) {
  return getRuleContext<RDFTESLAParser::TripleContext>(i);
}


size_t RDFTESLAParser::Rdf_patternContext::getRuleIndex() const {
  return RDFTESLAParser::RuleRdf_pattern;
}

void RDFTESLAParser::Rdf_patternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRdf_pattern(this);
}

void RDFTESLAParser::Rdf_patternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRdf_pattern(this);
}

RDFTESLAParser::Rdf_patternContext* RDFTESLAParser::rdf_pattern() {
  Rdf_patternContext *_localctx = _tracker.createInstance<Rdf_patternContext>(_ctx, getState());
  enterRule(_localctx, 54, RDFTESLAParser::RuleRdf_pattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(RDFTESLAParser::T__9);
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RDFTESLAParser::T__15)
      | (1ULL << RDFTESLAParser::URI_NAME)
      | (1ULL << RDFTESLAParser::SPARQL_VAR))) != 0)) {
      setState(244);
      triple();
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    match(RDFTESLAParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ce_definitionContext ------------------------------------------------------------------

RDFTESLAParser::Ce_definitionContext::Ce_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Ce_definitionContext::EVT_NAME() {
  return getToken(RDFTESLAParser::EVT_NAME, 0);
}

RDFTESLAParser::Rdf_patternContext* RDFTESLAParser::Ce_definitionContext::rdf_pattern() {
  return getRuleContext<RDFTESLAParser::Rdf_patternContext>(0);
}


size_t RDFTESLAParser::Ce_definitionContext::getRuleIndex() const {
  return RDFTESLAParser::RuleCe_definition;
}

void RDFTESLAParser::Ce_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCe_definition(this);
}

void RDFTESLAParser::Ce_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCe_definition(this);
}

RDFTESLAParser::Ce_definitionContext* RDFTESLAParser::ce_definition() {
  Ce_definitionContext *_localctx = _tracker.createInstance<Ce_definitionContext>(_ctx, getState());
  enterRule(_localctx, 56, RDFTESLAParser::RuleCe_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(RDFTESLAParser::EVT_NAME);
    setState(253);
    match(RDFTESLAParser::T__8);
    setState(254);
    rdf_pattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

RDFTESLAParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RDFTESLAParser::TerminatorContext* RDFTESLAParser::PatternContext::terminator() {
  return getRuleContext<RDFTESLAParser::TerminatorContext>(0);
}

std::vector<RDFTESLAParser::Pattern_predicateContext *> RDFTESLAParser::PatternContext::pattern_predicate() {
  return getRuleContexts<RDFTESLAParser::Pattern_predicateContext>();
}

RDFTESLAParser::Pattern_predicateContext* RDFTESLAParser::PatternContext::pattern_predicate(size_t i) {
  return getRuleContext<RDFTESLAParser::Pattern_predicateContext>(i);
}

std::vector<RDFTESLAParser::Pattern_b_predicateContext *> RDFTESLAParser::PatternContext::pattern_b_predicate() {
  return getRuleContexts<RDFTESLAParser::Pattern_b_predicateContext>();
}

RDFTESLAParser::Pattern_b_predicateContext* RDFTESLAParser::PatternContext::pattern_b_predicate(size_t i) {
  return getRuleContext<RDFTESLAParser::Pattern_b_predicateContext>(i);
}


size_t RDFTESLAParser::PatternContext::getRuleIndex() const {
  return RDFTESLAParser::RulePattern;
}

void RDFTESLAParser::PatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern(this);
}

void RDFTESLAParser::PatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern(this);
}

RDFTESLAParser::PatternContext* RDFTESLAParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 58, RDFTESLAParser::RulePattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    terminator();
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(260);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RDFTESLAParser::T__4) {
        setState(257);
        pattern_predicate();
        setState(262);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(263);
      pattern_predicate();
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RDFTESLAParser::T__3

      || _la == RDFTESLAParser::T__4) {
        setState(264);
        pattern_b_predicate();
        setState(269);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionsContext ------------------------------------------------------------------

RDFTESLAParser::DefinitionsContext::DefinitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RDFTESLAParser::StaticAttr_definitionContext *> RDFTESLAParser::DefinitionsContext::staticAttr_definition() {
  return getRuleContexts<RDFTESLAParser::StaticAttr_definitionContext>();
}

RDFTESLAParser::StaticAttr_definitionContext* RDFTESLAParser::DefinitionsContext::staticAttr_definition(size_t i) {
  return getRuleContext<RDFTESLAParser::StaticAttr_definitionContext>(i);
}

std::vector<RDFTESLAParser::Attr_definitionContext *> RDFTESLAParser::DefinitionsContext::attr_definition() {
  return getRuleContexts<RDFTESLAParser::Attr_definitionContext>();
}

RDFTESLAParser::Attr_definitionContext* RDFTESLAParser::DefinitionsContext::attr_definition(size_t i) {
  return getRuleContext<RDFTESLAParser::Attr_definitionContext>(i);
}


size_t RDFTESLAParser::DefinitionsContext::getRuleIndex() const {
  return RDFTESLAParser::RuleDefinitions;
}

void RDFTESLAParser::DefinitionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitions(this);
}

void RDFTESLAParser::DefinitionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitions(this);
}

RDFTESLAParser::DefinitionsContext* RDFTESLAParser::definitions() {
  DefinitionsContext *_localctx = _tracker.createInstance<DefinitionsContext>(_ctx, getState());
  enterRule(_localctx, 60, RDFTESLAParser::RuleDefinitions);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(272);
      staticAttr_definition();
      break;
    }

    case 2: {
      setState(273);
      attr_definition();
      break;
    }

    }
    setState(283);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RDFTESLAParser::T__6) {
      setState(276);
      match(RDFTESLAParser::T__6);
      setState(279);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        setState(277);
        staticAttr_definition();
        break;
      }

      case 2: {
        setState(278);
        attr_definition();
        break;
      }

      }
      setState(285);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConsumingContext ------------------------------------------------------------------

RDFTESLAParser::ConsumingContext::ConsumingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RDFTESLAParser::ConsumingContext::EVT_NAME() {
  return getTokens(RDFTESLAParser::EVT_NAME);
}

tree::TerminalNode* RDFTESLAParser::ConsumingContext::EVT_NAME(size_t i) {
  return getToken(RDFTESLAParser::EVT_NAME, i);
}


size_t RDFTESLAParser::ConsumingContext::getRuleIndex() const {
  return RDFTESLAParser::RuleConsuming;
}

void RDFTESLAParser::ConsumingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConsuming(this);
}

void RDFTESLAParser::ConsumingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConsuming(this);
}

RDFTESLAParser::ConsumingContext* RDFTESLAParser::consuming() {
  ConsumingContext *_localctx = _tracker.createInstance<ConsumingContext>(_ctx, getState());
  enterRule(_localctx, 62, RDFTESLAParser::RuleConsuming);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(RDFTESLAParser::EVT_NAME);
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RDFTESLAParser::T__6) {
      setState(287);
      match(RDFTESLAParser::T__6);
      setState(288);
      match(RDFTESLAParser::EVT_NAME);
      setState(293);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ending_ruleContext ------------------------------------------------------------------

RDFTESLAParser::Ending_ruleContext::Ending_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RDFTESLAParser::Ending_ruleContext::getRuleIndex() const {
  return RDFTESLAParser::RuleEnding_rule;
}

void RDFTESLAParser::Ending_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnding_rule(this);
}

void RDFTESLAParser::Ending_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnding_rule(this);
}

RDFTESLAParser::Ending_ruleContext* RDFTESLAParser::ending_rule() {
  Ending_ruleContext *_localctx = _tracker.createInstance<Ending_ruleContext>(_ctx, getState());
  enterRule(_localctx, 64, RDFTESLAParser::RuleEnding_rule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(RDFTESLAParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trex_rdf_ruleContext ------------------------------------------------------------------

RDFTESLAParser::Trex_rdf_ruleContext::Trex_rdf_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::ASSIGN() {
  return getToken(RDFTESLAParser::ASSIGN, 0);
}

RDFTESLAParser::Event_declarationsContext* RDFTESLAParser::Trex_rdf_ruleContext::event_declarations() {
  return getRuleContext<RDFTESLAParser::Event_declarationsContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::DEFINE() {
  return getToken(RDFTESLAParser::DEFINE, 0);
}

RDFTESLAParser::Ce_definitionContext* RDFTESLAParser::Trex_rdf_ruleContext::ce_definition() {
  return getRuleContext<RDFTESLAParser::Ce_definitionContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::FROM() {
  return getToken(RDFTESLAParser::FROM, 0);
}

RDFTESLAParser::PatternContext* RDFTESLAParser::Trex_rdf_ruleContext::pattern() {
  return getRuleContext<RDFTESLAParser::PatternContext>(0);
}

RDFTESLAParser::Ending_ruleContext* RDFTESLAParser::Trex_rdf_ruleContext::ending_rule() {
  return getRuleContext<RDFTESLAParser::Ending_ruleContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::WITH() {
  return getToken(RDFTESLAParser::WITH, 0);
}

RDFTESLAParser::Packet_referenceContext* RDFTESLAParser::Trex_rdf_ruleContext::packet_reference() {
  return getRuleContext<RDFTESLAParser::Packet_referenceContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::WHERE() {
  return getToken(RDFTESLAParser::WHERE, 0);
}

RDFTESLAParser::DefinitionsContext* RDFTESLAParser::Trex_rdf_ruleContext::definitions() {
  return getRuleContext<RDFTESLAParser::DefinitionsContext>(0);
}

tree::TerminalNode* RDFTESLAParser::Trex_rdf_ruleContext::CONSUMING() {
  return getToken(RDFTESLAParser::CONSUMING, 0);
}

RDFTESLAParser::ConsumingContext* RDFTESLAParser::Trex_rdf_ruleContext::consuming() {
  return getRuleContext<RDFTESLAParser::ConsumingContext>(0);
}


size_t RDFTESLAParser::Trex_rdf_ruleContext::getRuleIndex() const {
  return RDFTESLAParser::RuleTrex_rdf_rule;
}

void RDFTESLAParser::Trex_rdf_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrex_rdf_rule(this);
}

void RDFTESLAParser::Trex_rdf_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RDFTESLAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrex_rdf_rule(this);
}

RDFTESLAParser::Trex_rdf_ruleContext* RDFTESLAParser::trex_rdf_rule() {
  Trex_rdf_ruleContext *_localctx = _tracker.createInstance<Trex_rdf_ruleContext>(_ctx, getState());
  enterRule(_localctx, 66, RDFTESLAParser::RuleTrex_rdf_rule);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(RDFTESLAParser::ASSIGN);
    setState(297);
    event_declarations();
    setState(298);
    match(RDFTESLAParser::DEFINE);
    setState(299);
    ce_definition();
    setState(300);
    match(RDFTESLAParser::FROM);
    setState(301);
    pattern();
    setState(304);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RDFTESLAParser::WITH) {
      setState(302);
      match(RDFTESLAParser::WITH);
      setState(303);
      packet_reference();
    }
    setState(308);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RDFTESLAParser::WHERE) {
      setState(306);
      match(RDFTESLAParser::WHERE);
      setState(307);
      definitions();
    }
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RDFTESLAParser::CONSUMING) {
      setState(310);
      match(RDFTESLAParser::CONSUMING);
      setState(311);
      consuming();
    }
    setState(314);
    ending_rule();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool RDFTESLAParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RDFTESLAParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> RDFTESLAParser::_decisionToDFA;
atn::PredictionContextCache RDFTESLAParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RDFTESLAParser::_atn;
std::vector<uint16_t> RDFTESLAParser::_serializedATN;

std::vector<std::string> RDFTESLAParser::_ruleNames = {
  "static_reference", "packet_reference", "param_atom", "agg_one_reference", 
  "agg_between", "aggregate_atom", "expr", "staticAttr_definition", "attr_definition", 
  "attr_constraint", "attr_parameter", "predicate", "event_alias", "terminator", 
  "positive_predicate", "neg_one_reference", "neg_between", "negative_predicate", 
  "between_predicate", "pattern_predicate", "pattern_b_predicate", "event_declaration", 
  "event_declarations", "prefix_uri", "full_uri", "uri", "triple", "rdf_pattern", 
  "ce_definition", "pattern", "definitions", "consuming", "ending_rule", 
  "trex_rdf_rule"
};

std::vector<std::string> RDFTESLAParser::_literalNames = {
  "", "'.'", "'within'", "'from'", "'between'", "'and'", "'('", "','", "')'", 
  "':='", "'['", "']'", "'as'", "'not'", "'=>'", "':'", "'<'", "'>'", "';'", 
  "'Assign'", "'Define'", "'From'", "'With'", "'Where'", "'Consuming'"
};

std::vector<std::string> RDFTESLAParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "ASSIGN", "DEFINE", "FROM", "WITH", "WHERE", "CONSUMING", "VALTYPE", 
  "SEL_POLICY", "AGGR_FUN", "OPERATOR", "BINOP_MUL", "BINOP_ADD", "INT_VAL", 
  "FLOAT_VAL", "BOOL_VAL", "STRING_VAL", "SPARQL_QUERY", "EVT_NAME", "URI_NAME", 
  "SPARQL_VAR", "WS"
};

dfa::Vocabulary RDFTESLAParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RDFTESLAParser::_tokenNames;

RDFTESLAParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 
    0x3, 0x29, 0x13f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4f, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x61, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x7, 0x7, 0x68, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x6b, 0xb, 0x7, 0x5, 0x7, 0x6d, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x73, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x7c, 0xa, 0x8, 0x5, 
    0x8, 0x7e, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x86, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x89, 0xb, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa2, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0xc0, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xc9, 0xa, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x5, 0x16, 0xce, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xd7, 0xa, 
    0x18, 0xc, 0x18, 0xe, 0x18, 0xda, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x5, 0x1b, 0xe6, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0xea, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xee, 0xa, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xf2, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1d, 0x3, 0x1d, 0x7, 0x1d, 0xf8, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0xfb, 
    0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x105, 0xa, 0x1f, 0xc, 0x1f, 
    0xe, 0x1f, 0x108, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x10c, 
    0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x10f, 0xb, 0x1f, 0x5, 0x1f, 0x111, 
    0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x115, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x11a, 0xa, 0x20, 0x7, 0x20, 0x11c, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x11f, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0x124, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x127, 
    0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x133, 
    0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x137, 0xa, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x13b, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x2, 0x3, 0xe, 0x24, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
    0x44, 0x2, 0x3, 0x3, 0x2, 0x21, 0x24, 0x13b, 0x2, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x48, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0xa, 0x55, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x96, 0x3, 0x2, 0x2, 0x2, 0x18, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0x24, 0xba, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x32, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x36, 0xe9, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x114, 0x3, 0x2, 0x2, 0x2, 0x40, 0x120, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x128, 0x3, 0x2, 0x2, 0x2, 0x44, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x9, 0x2, 0x2, 0x2, 0x47, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x49, 0x7, 0x26, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x28, 0x2, 0x2, 0x4b, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4f, 0x5, 0x4, 0x3, 0x2, 0x4d, 0x4f, 0x5, 0x2, 0x2, 0x2, 0x4e, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x4, 0x2, 0x2, 0x51, 0x52, 0x7, 
    0x21, 0x2, 0x2, 0x52, 0x53, 0x7, 0x5, 0x2, 0x2, 0x53, 0x54, 0x7, 0x26, 
    0x2, 0x2, 0x54, 0x9, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x6, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0x26, 0x2, 0x2, 0x57, 0x58, 0x7, 0x7, 0x2, 0x2, 
    0x58, 0x59, 0x7, 0x26, 0x2, 0x2, 0x59, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5b, 0x7, 0x1d, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x8, 0x2, 0x2, 0x5c, 0x5d, 
    0x5, 0x4, 0x3, 0x2, 0x5d, 0x6c, 0x7, 0x8, 0x2, 0x2, 0x5e, 0x61, 0x5, 
    0x16, 0xc, 0x2, 0x5f, 0x61, 0x5, 0x14, 0xb, 0x2, 0x60, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x65, 0x7, 0x9, 0x2, 0x2, 0x63, 0x66, 0x5, 0x16, 0xc, 0x2, 
    0x64, 0x66, 0x5, 0x14, 0xb, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x7, 0xa, 0x2, 0x2, 0x6f, 0x72, 0x7, 0xa, 0x2, 0x2, 0x70, 
    0x73, 0x5, 0x8, 0x5, 0x2, 0x71, 0x73, 0x5, 0xa, 0x6, 0x2, 0x72, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x75, 0x8, 0x8, 0x1, 0x2, 0x75, 0x76, 0x7, 0x8, 
    0x2, 0x2, 0x76, 0x77, 0x5, 0xe, 0x8, 0x2, 0x77, 0x78, 0x7, 0xa, 0x2, 
    0x2, 0x78, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x5, 0x6, 0x4, 0x2, 
    0x7a, 0x7c, 0x5, 0xc, 0x7, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x80, 0xc, 0x6, 0x2, 0x2, 0x80, 0x81, 0x7, 0x1f, 
    0x2, 0x2, 0x81, 0x86, 0x5, 0xe, 0x8, 0x7, 0x82, 0x83, 0xc, 0x5, 0x2, 
    0x2, 0x83, 0x84, 0x7, 0x20, 0x2, 0x2, 0x84, 0x86, 0x5, 0xe, 0x8, 0x6, 
    0x85, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x85, 0x82, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0xf, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x28, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0xb, 
    0x2, 0x2, 0x8c, 0x8d, 0x5, 0x2, 0x2, 0x2, 0x8d, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x7, 0x28, 0x2, 0x2, 0x8f, 0x90, 0x7, 0xb, 0x2, 0x2, 
    0x90, 0x91, 0x5, 0xe, 0x8, 0x2, 0x91, 0x13, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x93, 0x7, 0x28, 0x2, 0x2, 0x93, 0x94, 0x7, 0x1e, 0x2, 0x2, 0x94, 0x95, 
    0x5, 0x2, 0x2, 0x2, 0x95, 0x15, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 
    0xc, 0x2, 0x2, 0x97, 0x98, 0x7, 0x1b, 0x2, 0x2, 0x98, 0x99, 0x7, 0xd, 
    0x2, 0x2, 0x99, 0x9a, 0x7, 0x28, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x1e, 0x2, 
    0x2, 0x9b, 0x9c, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9e, 0x7, 0x26, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0xb, 0x2, 0x2, 0x9f, 
    0xa1, 0x7, 0x25, 0x2, 0x2, 0xa0, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa1, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0xe, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x26, 
    0x2, 0x2, 0xa5, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x18, 0xd, 
    0x2, 0xa7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x7, 0x2, 0x2, 
    0xa9, 0xaa, 0x7, 0x1c, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x18, 0xd, 0x2, 0xab, 
    0xac, 0x7, 0x4, 0x2, 0x2, 0xac, 0xad, 0x7, 0x21, 0x2, 0x2, 0xad, 0xae, 
    0x7, 0x5, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x26, 0x2, 0x2, 0xaf, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x4, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x21, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0x5, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x26, 0x2, 
    0x2, 0xb4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x6, 0x2, 0x2, 
    0xb6, 0xb7, 0x7, 0x26, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x7, 0x2, 0x2, 0xb8, 
    0xb9, 0x7, 0x26, 0x2, 0x2, 0xb9, 0x23, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x7, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0xf, 0x2, 0x2, 0xbc, 0xbf, 0x5, 
    0x18, 0xd, 0x2, 0xbd, 0xc0, 0x5, 0x20, 0x11, 0x2, 0xbe, 0xc0, 0x5, 0x22, 
    0x12, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x6, 0x2, 0x2, 
    0xc2, 0xc3, 0x7, 0x26, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x7, 0x2, 0x2, 0xc4, 
    0xc5, 0x7, 0x26, 0x2, 0x2, 0xc5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 
    0x5, 0x1e, 0x10, 0x2, 0xc7, 0xc9, 0x5, 0x24, 0x13, 0x2, 0xc8, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xce, 0x5, 0x1e, 0x10, 0x2, 0xcb, 0xce, 0x5, 0x26, 
    0x14, 0x2, 0xcc, 0xce, 0x5, 0x24, 0x13, 0x2, 0xcd, 0xca, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x21, 0x2, 0x2, 0xd0, 
    0xd1, 0x7, 0x10, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x26, 0x2, 0x2, 0xd2, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd8, 0x5, 0x2c, 0x17, 0x2, 0xd4, 0xd5, 0x7, 
    0x9, 0x2, 0x2, 0xd5, 0xd7, 0x5, 0x2c, 0x17, 0x2, 0xd6, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x27, 0x2, 0x2, 0xdc, 
    0xdd, 0x7, 0x11, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x27, 0x2, 0x2, 0xde, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x12, 0x2, 0x2, 0xe0, 0xe1, 0x7, 
    0x27, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x13, 0x2, 0x2, 0xe2, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe6, 0x5, 0x30, 0x19, 0x2, 0xe4, 0xe6, 0x5, 0x32, 0x1a, 
    0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe6, 0x35, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x5, 0x34, 0x1b, 0x2, 0xe8, 
    0xea, 0x7, 0x28, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x5, 
    0x34, 0x1b, 0x2, 0xec, 0xee, 0x7, 0x28, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0xf2, 0x5, 0x34, 0x1b, 0x2, 0xf0, 0xf2, 0x7, 0x28, 0x2, 0x2, 
    0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x3, 0x2, 0x2, 0xf4, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xf9, 0x7, 0xc, 0x2, 0x2, 0xf6, 0xf8, 0x5, 
    0x36, 0x1c, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0xd, 0x2, 0x2, 0xfd, 0x39, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xff, 0x7, 0x26, 0x2, 0x2, 0xff, 0x100, 0x7, 0xb, 0x2, 0x2, 0x100, 0x101, 
    0x5, 0x38, 0x1d, 0x2, 0x101, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x102, 0x110, 
    0x5, 0x1c, 0xf, 0x2, 0x103, 0x105, 0x5, 0x28, 0x15, 0x2, 0x104, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10d, 
    0x5, 0x28, 0x15, 0x2, 0x10a, 0x10c, 0x5, 0x2a, 0x16, 0x2, 0x10b, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x109, 0x3, 0x2, 0x2, 0x2, 0x111, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x115, 0x5, 0x10, 0x9, 0x2, 0x113, 0x115, 0x5, 
    0x12, 0xa, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x115, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x7, 
    0x9, 0x2, 0x2, 0x117, 0x11a, 0x5, 0x10, 0x9, 0x2, 0x118, 0x11a, 0x5, 
    0x12, 0xa, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x11a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x116, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 
    0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x125, 0x7, 0x26, 
    0x2, 0x2, 0x121, 0x122, 0x7, 0x9, 0x2, 0x2, 0x122, 0x124, 0x7, 0x26, 
    0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x41, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x129, 0x7, 0x14, 0x2, 0x2, 0x129, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x12b, 0x7, 0x15, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x2e, 0x18, 
    0x2, 0x12c, 0x12d, 0x7, 0x16, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x3a, 0x1e, 
    0x2, 0x12e, 0x12f, 0x7, 0x17, 0x2, 0x2, 0x12f, 0x132, 0x5, 0x3c, 0x1f, 
    0x2, 0x130, 0x131, 0x7, 0x18, 0x2, 0x2, 0x131, 0x133, 0x5, 0x4, 0x3, 
    0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x19, 0x2, 
    0x2, 0x135, 0x137, 0x5, 0x3e, 0x20, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x139, 0x7, 0x1a, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x40, 0x21, 
    0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x42, 0x22, 
    0x2, 0x13d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x20, 0x4e, 0x60, 0x65, 0x69, 
    0x6c, 0x72, 0x7b, 0x7d, 0x85, 0x87, 0xa1, 0xbf, 0xc8, 0xcd, 0xd8, 0xe5, 
    0xe9, 0xed, 0xf1, 0xf9, 0x106, 0x10d, 0x110, 0x114, 0x119, 0x11d, 0x125, 
    0x132, 0x136, 0x13a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RDFTESLAParser::Initializer RDFTESLAParser::_init;
