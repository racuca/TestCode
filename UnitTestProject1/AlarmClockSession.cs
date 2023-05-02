using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Appium.Windows;
using OpenQA.Selenium.Remote;
using System;
using System.Threading;

namespace UnitTestProject1
{
    class AlarmClockSession
    {
        private const string WindowsApplicationDriverUrl = "http://127.0.0.1:4723";
        private const string AlarmClockAppId = "Microsoft.WindowsAlarms_8wekyb3d8bbwe!App";

        protected static WindowsDriver<WindowsElement> session;
        protected static RemoteTouchScreen touchScreen;

        public static void Setup(TestContext context)
        {
            // Launch Alarms & Clock application if it is not yet launched
            if (session == null || touchScreen == null)
            {
                TearDown();

                // Create a new session to bring up the Alarms & Clock application
                DesiredCapabilities appCapabilities = new DesiredCapabilities();
                appCapabilities.SetCapability("app", AlarmClockAppId);
                session = new WindowsDriver<WindowsElement>(new Uri(WindowsApplicationDriverUrl), appCapabilities);
                Assert.IsNotNull(session);
                Assert.IsNotNull(session.SessionId);

                // Set implicit timeout to 1.5 seconds to make element search to retry every 500 ms for at most three times
                session.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(1.5);

                // Initialize touch screen object
                touchScreen = new RemoteTouchScreen(session);
                Assert.IsNotNull(touchScreen);
            }
        }

        public static void TearDown()
        {
            // Cleanup RemoteTouchScreen object if initialized
            touchScreen = null;

            // Close the application and delete the session
            if (session != null)
            {
                session.Quit();
                session = null;
            }
        }

        [TestInitialize]
        public virtual void TestInit()
        {
            WindowsElement alarmButtonElement = null;

            // Attempt to go back to the main page in case Alarms & Clock app is started in EditAlarm view
            try
            {
                alarmButtonElement = session.FindElementByAccessibilityId("AlarmButton");
            }
            catch
            {
                // Click cancel button if application is in a nested page such as New Alarm or New Timer
                session.FindElementByAccessibilityId("CancelButton").Click();
                Thread.Sleep(TimeSpan.FromSeconds(1));
                alarmButtonElement = session.FindElementByAccessibilityId("AlarmButton");
            }

            // Verify that the app is in the main view showing alarmButtonElement
            Assert.IsNotNull(alarmButtonElement);
            Assert.IsTrue(alarmButtonElement.Displayed);
        }
    }
}
