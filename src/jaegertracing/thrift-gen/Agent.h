/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Agent_H
#define Agent_H

#include <thrift/TDispatchProcessor.h>
#include "agent_types.h"

namespace jaegertracing { namespace agent { namespace thrift {

class AgentIf {
 public:
  virtual ~AgentIf() {}
  virtual void emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans) = 0;
  virtual void emitBatch(const  ::jaegertracing::thrift::Batch& batch) = 0;
};

class AgentIfFactory {
 public:
  typedef AgentIf Handler;

  virtual ~AgentIfFactory() {}

  virtual AgentIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(AgentIf* /* handler */) = 0;
};

class AgentIfSingletonFactory : virtual public AgentIfFactory {
 public:
  AgentIfSingletonFactory(const boost::shared_ptr<AgentIf>& iface) : iface_(iface) {}
  virtual ~AgentIfSingletonFactory() {}

  virtual AgentIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(AgentIf* /* handler */) {}

 protected:
  boost::shared_ptr<AgentIf> iface_;
};

class AgentNull : virtual public AgentIf {
 public:
  virtual ~AgentNull() {}
  void emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & /* spans */) {
    return;
  }
  void emitBatch(const  ::jaegertracing::thrift::Batch& /* batch */) {
    return;
  }
};

typedef struct _Agent_emitZipkinBatch_args__isset {
  _Agent_emitZipkinBatch_args__isset() : spans(false) {}
  bool spans :1;
} _Agent_emitZipkinBatch_args__isset;

class Agent_emitZipkinBatch_args {
 public:

  static const char* ascii_fingerprint; // = "83B240223F8FA813FDD0EA4C9255FAA4";
  static const uint8_t binary_fingerprint[16]; // = {0x83,0xB2,0x40,0x22,0x3F,0x8F,0xA8,0x13,0xFD,0xD0,0xEA,0x4C,0x92,0x55,0xFA,0xA4};

  Agent_emitZipkinBatch_args(const Agent_emitZipkinBatch_args&);
  Agent_emitZipkinBatch_args& operator=(const Agent_emitZipkinBatch_args&);
  Agent_emitZipkinBatch_args() {
  }

  virtual ~Agent_emitZipkinBatch_args() throw();
  std::vector< ::twitter::zipkin::thrift::Span>  spans;

  _Agent_emitZipkinBatch_args__isset __isset;

  void __set_spans(const std::vector< ::twitter::zipkin::thrift::Span> & val);

  bool operator == (const Agent_emitZipkinBatch_args & rhs) const
  {
    if (!(spans == rhs.spans))
      return false;
    return true;
  }
  bool operator != (const Agent_emitZipkinBatch_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Agent_emitZipkinBatch_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Agent_emitZipkinBatch_args& obj);
};


class Agent_emitZipkinBatch_pargs {
 public:

  static const char* ascii_fingerprint; // = "83B240223F8FA813FDD0EA4C9255FAA4";
  static const uint8_t binary_fingerprint[16]; // = {0x83,0xB2,0x40,0x22,0x3F,0x8F,0xA8,0x13,0xFD,0xD0,0xEA,0x4C,0x92,0x55,0xFA,0xA4};


  virtual ~Agent_emitZipkinBatch_pargs() throw();
  const std::vector< ::twitter::zipkin::thrift::Span> * spans;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Agent_emitZipkinBatch_pargs& obj);
};

typedef struct _Agent_emitBatch_args__isset {
  _Agent_emitBatch_args__isset() : batch(false) {}
  bool batch :1;
} _Agent_emitBatch_args__isset;

class Agent_emitBatch_args {
 public:

  static const char* ascii_fingerprint; // = "4A47EC6C4659312572A7C4824E9AADB9";
  static const uint8_t binary_fingerprint[16]; // = {0x4A,0x47,0xEC,0x6C,0x46,0x59,0x31,0x25,0x72,0xA7,0xC4,0x82,0x4E,0x9A,0xAD,0xB9};

  Agent_emitBatch_args(const Agent_emitBatch_args&);
  Agent_emitBatch_args& operator=(const Agent_emitBatch_args&);
  Agent_emitBatch_args() {
  }

  virtual ~Agent_emitBatch_args() throw();
   ::jaegertracing::thrift::Batch batch;

  _Agent_emitBatch_args__isset __isset;

  void __set_batch(const  ::jaegertracing::thrift::Batch& val);

  bool operator == (const Agent_emitBatch_args & rhs) const
  {
    if (!(batch == rhs.batch))
      return false;
    return true;
  }
  bool operator != (const Agent_emitBatch_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Agent_emitBatch_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Agent_emitBatch_args& obj);
};


class Agent_emitBatch_pargs {
 public:

  static const char* ascii_fingerprint; // = "4A47EC6C4659312572A7C4824E9AADB9";
  static const uint8_t binary_fingerprint[16]; // = {0x4A,0x47,0xEC,0x6C,0x46,0x59,0x31,0x25,0x72,0xA7,0xC4,0x82,0x4E,0x9A,0xAD,0xB9};


  virtual ~Agent_emitBatch_pargs() throw();
  const  ::jaegertracing::thrift::Batch* batch;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Agent_emitBatch_pargs& obj);
};

class AgentClient : virtual public AgentIf {
 public:
  AgentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  AgentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans);
  void send_emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans);
  void emitBatch(const  ::jaegertracing::thrift::Batch& batch);
  void send_emitBatch(const  ::jaegertracing::thrift::Batch& batch);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class AgentProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<AgentIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (AgentProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_emitZipkinBatch(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_emitBatch(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  AgentProcessor(boost::shared_ptr<AgentIf> iface) :
    iface_(iface) {
    processMap_["emitZipkinBatch"] = &AgentProcessor::process_emitZipkinBatch;
    processMap_["emitBatch"] = &AgentProcessor::process_emitBatch;
  }

  virtual ~AgentProcessor() {}
};

class AgentProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  AgentProcessorFactory(const ::boost::shared_ptr< AgentIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< AgentIfFactory > handlerFactory_;
};

class AgentMultiface : virtual public AgentIf {
 public:
  AgentMultiface(std::vector<boost::shared_ptr<AgentIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~AgentMultiface() {}
 protected:
  std::vector<boost::shared_ptr<AgentIf> > ifaces_;
  AgentMultiface() {}
  void add(boost::shared_ptr<AgentIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->emitZipkinBatch(spans);
    }
    ifaces_[i]->emitZipkinBatch(spans);
  }

  void emitBatch(const  ::jaegertracing::thrift::Batch& batch) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->emitBatch(batch);
    }
    ifaces_[i]->emitBatch(batch);
  }

};

}}} // namespace

#endif
