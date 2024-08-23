//========================================================================
// GLAD headers
extern "C" {
    #include <glad/glad.h>
} // extern "C"

#include <stdexcept>

//========================================================================
// A simple class to load OpenGL via glad.
class glad
{
public:
    //========================================================================
    glad(::GLADloadproc loadproc);
    //========================================================================
    virtual ~glad()
    {
        // There is no unloading function...
    }
};

// ===========================================================
struct glad_exception : std::exception
{
    std::string m_Message;

    //========================================================================
    glad_exception(std::string message, int line_nr, char const * in_file)
    {
        m_Message =  std::string("glad_exception in file ") + std::string(in_file);
        m_Message += std::string(", in line ") + std::to_string(line_nr) + ":\n";
        m_Message += message;
    }
    //========================================================================
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override
    {
        return m_Message.c_str();
    }
    //========================================================================
}; // struct glad_exception


//========================================================================
// End of file.
//========================================================================
