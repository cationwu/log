#include "../logs/wkslog.h"


void loggerTest(const std::string &logger_name) {
    wkslog::Logger::ptr lp = wkslog::getLogger(logger_name);
    assert(lp.get());
    LOGF("------------example--------------------");
    lp->debug("%s", "logger->debug");
    lp->info("%s", "logger->info");
    lp->warn("%s", "logger->warn");
    lp->error("%s", "logger->error");
    lp->fatal("%s", "logger->fatal");
    LOG_DEBUG(lp, "%s", "LOG_DEBUG");
    LOG_INFO(lp, "%s", "LOG_INFO");
    LOG_WARN(lp, "%s", "LOG_WARN");
    LOG_ERROR(lp, "%s", "LOG_ERROR");
    LOG_FATAL(lp, "%s", "LOG_FATAL");
    LOGF("---------------------------------------");
    
    // std::string log_msg = "hello -wks";
    // size_t fsize = 0;
    // size_t count = 0;
    // while(count < 1000000) {
    //     std::string msg = log_msg + std::to_string(count++);
    //     lp->error("%s", msg.c_str());
    // }
}
void functional_test() {
    wkslog::GlobalLoggerBuilder::ptr lbp(new wkslog::GlobalLoggerBuilder);
    lbp->buildLoggerName("all_sink_logger");
    lbp->buildFormatter("[%d][%c][%f:%l][%p] %m%n");
    lbp->buildLoggerLevel(wkslog::LogLevel::value::DEBUG);
    lbp->buildSink<wkslog::StdoutSink>();
    lbp->buildSink<wkslog::FileSink>("./logs/async.log");
    lbp->buildSink<wkslog::RollSink>("./logs/roll-", 10 * 1024 * 1024);
    lbp->buildLoggerType(wkslog::Logger::Type::LOGGER_ASYNC);
    lbp->build(); 
    loggerTest("all_sink_logger");
}

void test1()
{
    wkslog::Logger::ptr kk=wkslog::rootLogger();
    LOGD("hello");
}

int main()
{
    functional_test();
    //test1();
    return 0;
}
