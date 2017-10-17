This project has been executed in Debug mode.

Project will mainly depict the creation of DLL using the quickest and simplest way i.e, using DEF file.

For giving the simplest understanding I have used the relative paths. You can modify the path of DLL as per your need.
Note: For most of the time at production code, DLL will be deployed with your application.

You can debug the 'DllApp' project and see the output.(Debug mode)
If you try to run the .exe from debug will fail and give error code as 126. This is because of the "Relative Path" mismatch. To run successfully,
copy the ".exe" near ".sln" and you will see output.

Read more about DEF files: https://docs.microsoft.com/en-us/cpp/build/reference/module-definition-dot-def-files