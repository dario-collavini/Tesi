
// Generated from RDFTESLA.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"




class  RDFTESLALexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, ASSIGN = 17, DEFINE = 18, FROM = 19, WITH = 20, 
    WHERE = 21, CONSUMING = 22, VALTYPE = 23, SEL_POLICY = 24, AGGR_FUN = 25, 
    OPERATOR = 26, BINOP_MUL = 27, BINOP_ADD = 28, INT_VAL = 29, FLOAT_VAL = 30, 
    BOOL_VAL = 31, STRING_VAL = 32, SPARQL_QUERY = 33, EVT_NAME = 34, URI_PREFIX_NAME = 35, 
    URI_FULL_NAME = 36, SPARQL_VAR = 37, WS = 38
  };

  RDFTESLALexer(antlr4::CharStream *input);
  ~RDFTESLALexer();


  std::stringstream ss; // can't make locals in lexer rules
  std::string str;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void STRING_VALAction(antlr4::RuleContext *context, size_t actionIndex);
  void SPARQL_QUERYAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

